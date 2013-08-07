// shh.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("����", ({ "shh"}));
	set("gender", "����");
	set("long","���̵�һ��������ʮ��Ǳ����ѧ��������������ϲ��
�ڻƻ�ʱǣһƥ������һ����멣���������������
ɽ�۵�ѩԭ�������ߵ����ա�˭���˽������ĵ�
�¼��أ�Ҳ����ѧ����߾�����ǽ����⽣Ӱ������
�ġ���������ҫ�������������ţ����Ķ�ͷ�������ƣ�
������񳣬������һ˿���������ˡ�\n");
	set("title", HIW"ʥ��"HIG"���������Ž���"NOR"���̵���ʮ�������"NOR);
	set("nickname", HIR"����"HIY"һЦ"NOR);
	set("age", 68);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 20);
	set("per", 20);
	set("int", 24);
	set("dex", 16);
	set("con", 22);
	set("str", 20);
	set("weiwang", 20);
	set("shen", 205010);
	set("combat_exp", 11313839);
	set("PKS", 1);
	set("MKS", 13844);

	set("max_jing", 616);
	set("jing", 616);
	set("max_qi", 1459);
	set("qi", 1459);
	set("max_jingli", 531);
	set("jingli", 531);
	set("max_neili", 4190);
	set("neili", 4190);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 300);
	set_skill("force", 300);
	set_skill("unarmed",260);
	set_skill("parry", 295);
	set_skill("dodge", 298);
	set_skill("sword", 260);
	set_skill("cuff", 260);
	set_skill("qishang-quan", 423);
	set_skill("qiankun-danuoyi", 260);
	set_skill("jiuyang-shengong", 282);
	set_skill("tianyu-qijian", 292);
	set_skill("shenxing-baibian", 435);
        set_skill("strike", 250);
        set_skill("hanbing-mianzhang", 283);
        set_skill("taoism", 120);
        set_skill("hand", 250);
        set_skill("hubo", 110);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "tianyu-qijian");
	map_skill("unarmed","qiankun-danuoyi");
	map_skill("cuff","qishang-quan");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("����",35, "����");
	setup();
	carry_object(__DIR__"shh_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  �������� (sword)                         - ��ɲ� 260/    0\n"+
"������ȭ (qishang-quan)                    - ��ɲ� 423/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 298/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 300/    0\n"+
"�������潣 (tianyu-qijian)                 - ��ɲ� 292/    0\n"+
"�������� (jiuyang-shengong)              - ��ɲ� 282/    0\n"+
"  ����д�� (literate)                      - ��ɲ� 300/    0\n"+
"  �����м� (parry)                         - ��ɲ� 295/    0\n"+
"�����аٱ� (shenxing-baibian)              - ��ɲ� 435/    0\n"+
"  ����ȭ�� (cuff)                          - ��ɲ� 260/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 260/    0\n"+
"  �����Ʒ� (strike)                        - ��ɲ� 250/    0\n"+
"  �������� (hanbing-mianzhang)             - ��ɲ� 283/    0\n"+
"  �����ַ� (hand)                          - ��ɲ� 250/    0\n"+
"  ��ѧ�ķ� (taoism)                        - ��Ȼ��� 120/    0\n"+
"  ���һ��� (hubo)                          - ������� 110/    0\n"+
"��Ǭ����Ų�� (qiankun-danuoyi)             - ��ɲ� 260/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  616/  616 (100%)    �� �� �� ��  531 /  531 (+0)\n"+
"�� �� Ѫ �� 1459/ 1459 (100%)    �� �� �� �� 4190 / 4190 (+0)\n"+
"�� ʳ �� ��    0/  300           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  300           �� �� �� ��  11313839\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"������������ʥ�����������Ž������µڶ��������̵���ʮ������ӡ�����һЦ������(Shh)\n"+
"\n"+
" ����һλ��ʮ����ʮ���µ��������࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 46]  ���ԣ�[ 54]  ���ǣ�[ 52]  ����[ 45]"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������  2100000            ս��������   2300000\n"+
" ս���˺���       30            ս��������         1\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 13844 ���ˣ������� 1 ����������ҡ�\n"+
"\n"+
" ��    ����   205010     Ǳ    �ܣ�   0 (100%)   ʵս���飺 11313839\n"+
" ��    ����       60     ����������   0          ����������       20\n"+
"\n", this_object());
	return 1;
}
