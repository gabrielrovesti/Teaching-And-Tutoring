load('T04_1129.mat');
load('T04_2_1129.mat');

mat_pre = T04_1129;
mat_post = T04_2_1129;

Function_def_CompletaPre(mat_pre)
Function_def_CompletaPost(mat_post)

% Unione dei grafici con stile corretto
def_UnioneGrafici('vert_pre.fig', 'vert_post.fig')
def_UnioneGrafici('norm_pre.fig', 'norm_post.fig')
def_UnioneGrafici('orr_pre.fig', 'orr_post.fig')
def_UnioneGrafici('int_pre.fig', 'int_post.fig')