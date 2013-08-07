// fall.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("������", ({ "news"}));
	set("gender", "����");
	set("long","���������������ᰮ���Ѻͽ��գ�������������ҹ��������
�ĳ�����¼��Ϊ��ż��������ˣ����е�ŵ��������
��ϰ��ˡ�����ò�����ˣ����䷢չ���ֵ��ٶȿ�ν��
ǰ�޹��˺������ߡ��������ؤ�ﵱС��ؤ���������ȫ�棬
ת����鶫�������廨�����������֮�ߣ�һ������С��\n");
	set("title", HIW"ʥ��"HIG"���������Ž���"NOR"���������Ŵ�ʦ��"NOR);
	set("nickname", HIR"��������"NOR);
	set("age", 18);
	set("class", "sword");
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 42);
	set("dex", 41);
	set("con", 42);
	set("str", 42);
	set("weiwang", 10);
	set("shen", 8623);
	set("combat_exp", 2995735);
	set("PKS", 1);
	set("MKS", 1968);

	set("max_jing", 250);
	set("jing", 250);
	set("max_qi", 1092);
	set("qi", 1092);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3650);
	set("neili", 3650);
	set("meili", 0);
	set("env/no_teach", "1");

	set_skill("literate", 200);
	set_skill("taoism", 99);
	set_skill("dodge", 199);
	set_skill("force", 219);
	set_skill("parry", 174);
	set_skill("unarmed",20);
	set_skill("sword", 298);
	set_skill("strike", 100);
	set_skill("bingxue-xinfa", 990);
	set_skill("snow-strike", 12);
	set_skill("snowstep", 226);
	set_skill("taixuan-gong", 251);
	set_skill("xueshan-sword", 304);

	map_skill("force", "bingxue-xinfa");
	map_skill("dodge", "snowstep");
	map_skill("parry", "xueshan-sword");
	map_skill("sword", "xueshan-sword");
	map_skill("unarmed","taixuan-gong");
	map_skill("strike","snow-strike");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("����",35, "����");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+

"�ԩ�������������������������������������������������������������������\n"+
"����ѩ�ķ� (bingxue-xinfa)                 - ����似 299/ 1464\n"+
"  �����Ṧ (dodge)                         - �ڻ��ͨ 199/   73\n"+
"  �����ڹ� (force)                         - ¯���� 219/ 9497\n"+
"  ����д�� (literate)                      - �ڻ��ͨ 200/  882\n"+
"  �����м� (parry)                         - ������� 174/   19\n"+
"����ѩӳ÷�� (snow-strike)                 - ��������  12/   34\n"+
"��÷ѩƮ�� (snowstep)                      - ��Ȼ���� 226/10062\n"+
"  �����Ʒ� (strike)                        - ƽ������ 100/    0\n"+
"  �������� (sword)                         - ����似 298/53415\n"+
"��̫���� (taixuan-gong)                    - ��Ȼ��ͨ 251/    0\n"+
"  ��ѧ�ķ� (taoism)                        - ��������  99/    0\n"+
"  ����ȭ�� (unarmed)                       - ����ҳ�  20/    2\n"+
"��ѩɽ���� (xueshan-sword)                 - �����뻯 304/40829\n"+
"�ԩ�������������������������������������������������������������������\n", this_object());
	return 1;
}
int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  250/  250 (100��)   �� �� �� ��    0 /    0 (+0)\n"+
"�� �� Ѫ �� 1092/ 1092 (100��)   �� �� �� �� 3650 / 3650 (+0)\n"+
"�� �� �� ��    8623              �� �� �� ��   50 /   50\n"+
"�� ʳ �� ��  256/  300           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��  179/  300           �� �� �� ��  2995735\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"�� ��  ʿ �����������Ž������������Ŵ�ʦ�֡��������񡹲�����(News)\n\n"+
" ����һλʮ����������Ը���ͨ���������࣬������һ��һ�ճ�ʱ��������\n"+
" ����[20/ 30]  ����[30/ 50]  ����[16/ 37]  ��[14/ 33]  ����[24/ 41]\n"+
" ����[25/ 34]  ��Ե[30/ 30]  ��ʶ[22/ 22]  ����[15/ 15]  ��ò[20/320]\n\n"+
" ���ʦ���� �����ڡ�        �㻹�Ǹ������\n"+
" ��������ʮ�����ƽ���ʮ����������ʮ����ͭǮ��\n\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 2115 ���ˣ������� 1 ����������ҡ�\n"+
" �㵽ĿǰΪֹ�ܹ����� 25 ���ˣ������� 19 ���Ƿ�����������\n\n"+
" ��    ����     8623     Ǳ    �ܣ�  20 ( 99%)   ʵս���飺  2959269\n"+
" ��    ����       60     ����������    22994     ����������       30\n"+
"\n", this_object());
	return 1;
}

