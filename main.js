const el=(tag,cls,txt)=>{const e=document.createElement(tag);if(cls)e.className=cls;if(txt)e.textContent=txt;return e};function media(p){const m=el('div','media');if(p.video){const v=el('video');v.src=p.video;v.muted=true;v.loop=true;v.playsInline=true;v.preload='none';if(p.image)v.poster=p.image;m.append(v)}else if(p.image){const i=el('img');i.src=p.image;i.alt=p.name;i.loading='lazy';m.append(i)}else{const a=el('div','art');a.style.setProperty('--tone',p.tone);a.append(el('span','',p.name.split(' ').map(s=>s[0]).join('')));m.append(a,el('span','placeholder','PROJECT MEDIA TO BE ADDED'))}return m}function tags(p){const t=el('div','tags');p.tags.forEach(x=>{const isSourceLink=x==='C++'&&p.sourceFiles&&document.querySelector('#detail');const tag=el(isSourceLink?'a':'span','',x);if(isSourceLink){tag.href='#source-code';tag.setAttribute('aria-label','C++ — view source code');}t.append(tag)});return t}const grid=document.querySelector('#projects-grid');if(grid){for(const p of projects.filter(project => project.showOnHome !== false)){const a=el('a','project'+(p.featured?' featured':''));a.href='project.html?id='+encodeURIComponent(p.id);a.dataset.type=p.type;const b=el('div','body');b.append(el('div','eyebrow',p.type+' / Gameplay & Technology'),el('h3','',p.name),el('p','',p.summary),tags(p));const f=el('div','foot');f.append(el('span','',p.role),el('span','arrow','View project ↗'));b.append(f);a.append(media(p),b);a.addEventListener('pointermove',e=>{const r=a.getBoundingClientRect();a.style.setProperty('--x',e.clientX-r.left+'px');a.style.setProperty('--y',e.clientY-r.top+'px')});const v=a.querySelector('video');if(v){a.addEventListener('pointerenter',()=>{if(!matchMedia('(prefers-reduced-motion: reduce)').matches)v.play().catch(()=>{})});a.addEventListener('pointerleave',()=>v.pause())}grid.append(a)}document.querySelectorAll('.filter').forEach(b=>b.addEventListener('click',()=>{document.querySelectorAll('.filter').forEach(x=>x.setAttribute('aria-pressed',String(x===b)));grid.querySelectorAll('.project').forEach(a=>a.hidden=b.dataset.filter!=='All'&&a.dataset.type!==b.dataset.filter)}))}const detail=document.querySelector('#detail');if(detail){const p=projects.find(x=>x.id===new URLSearchParams(location.search).get('id'));if(!p){detail.append(el('h1','','Project not found'))}else{document.title=p.name+' | Jennifer Borgny';detail.append(el('div','eyebrow',p.role),el('h1','',p.name),el('p','lead',p.summary),tags(p),media(p),el('h2','','Technical focus'));const list=el('ul');p.details.forEach(x=>list.append(el('li','',x)));detail.append(list,el('p','','Additional project documentation and gameplay media will be added.'));const v=detail.querySelector('video');if(v)v.controls=true}}

const heroesProject = projects.find(project => project.id === 'heroes-of-the-depth');
if (detail && heroesProject && new URLSearchParams(location.search).get('id') === heroesProject.id) {
  detail.classList.add('heroes-detail');
  const projectLinks = el('div', 'project-links');
  const itchLink = el('a', 'btn', 'Play / download on itch.io');
  itchLink.href = 'https://futuregames.itch.io/heroesofthedepth';
  projectLinks.append(itchLink);
  detail.querySelector('.tags').after(projectLinks);
  const placeholder = [...detail.querySelectorAll('p')].find(node => node.textContent === 'Additional project documentation and gameplay media will be added.');
  if (placeholder) placeholder.remove();
  const showcase = detail.querySelector('.media');
  const fullVideo = showcase.querySelector('video');
  fullVideo.preload = 'metadata';
  fullVideo.setAttribute('aria-label', 'Heroes of the Depth full gameplay showcase');
  showcase.before(el('h2', '', 'Gameplay systems showcase'));
  const systems = el('div', 'systems');
  for (const system of heroesProject.systems) {
    const row = el('section', 'system-row');
    const copy = el('div', 'system-copy');
    copy.append(el('h2', '', system.title), el('p', '', system.description));
    const figure = el('figure', 'system-clip');
    const video = el('video');
    video.src = 'assets/videos/' + system.video;
    video.controls = true;
    video.muted = true;
    video.loop = true;
    video.playsInline = true;
    video.preload = 'metadata';
    video.setAttribute('aria-label', system.title + ' gameplay demonstration');
    figure.append(video, el('figcaption', '', system.title + ' · Gameplay demonstration'));
    row.append(copy, figure);
    systems.append(row);
  }
  detail.append(systems);
}

if (detail && heroesProject && new URLSearchParams(location.search).get('id') === heroesProject.id && heroesProject.sourceFiles) {
  const sourceSection = el('section', 'source-section');
  sourceSection.id = 'source-code';
  sourceSection.tabIndex = -1;
  sourceSection.append(
    el('div', 'eyebrow', 'C++ implementation'),
    el('h2', '', 'Source code'),
    el('p', '', 'My player progression component handles experience, leveling and skill point upgrades, with Blueprint events for applying each upgrade. Expand a file to read the implementation, or view it on GitHub.')
  );
  for (const file of heroesProject.sourceFiles) {
    const panel = el('details', 'source-file');
    const summary = el('summary', '', file.name);
    const actions = el('div', 'source-actions');
    const github = el('a', 'btn', 'View on GitHub');
    github.href = 'https://github.com/Vanillifer/vanillifer.github.io/blob/portfolio-v1/' + file.path;
    const download = el('a', 'btn', 'Download file');
    download.href = file.path;
    download.download = file.name;
    actions.append(github, download);
    const pre = el('pre');
    pre.tabIndex = 0;
    pre.setAttribute('aria-label', file.name + ' source code');
    pre.append(el('code', 'language-cpp', file.content));
    panel.append(summary, actions, pre);
    sourceSection.append(panel);
  }
  detail.append(sourceSection);
}
