// rewj.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("����", ({ "rewj"}));
	set("gender", "����");
        set("long",
"��̶֪����һλ����ҡ�����ʦ�����ң�ƾ��һ�����
 �������֣��������޵�������֮�ߡ����⽭��Ϊ�˺�ˬ��
 ڶг��Ĭ����ƴ�ڻ����Ծ���գ��㽻���ѣ���һ����
 Ե���õ��ϻ�졣\n");
        set("title", "�����ɵڶ�������");
        set("nickname", HIR"һ��һ��"NOR);
	set("age", 27);
	set("class", "taoist");
	set("attitude", "friendly");
	
	set("kar", 20);
	set("per", 29);
	set("int", 31);
	set("dex", 14);
	set("con", 21);
	set("str", 16);
	set("weiwang", 30);
	set("shen", 47384);
	set("combat_exp", 1016246);
	set("PKS", 2);
	set("MKS", 73);
	
	set("max_jing", 596);
	set("jing", 596);
	set("max_qi", 1210);
	set("qi", 1210);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3096);
	set("neili", 3096);
	set("meili", 60);
	set("env/no_teach", "1");
	
	set_skill("literate", 180);
	set_skill("force", 212);
	set_skill("unarmed",200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("sword", 216);
	set_skill("cuff", 100);
	set_skill("leg", 101);
	set_skill("goplaying", 159);
	set_skill("luteplaying",159);
	set_skill("gambling",4);
	set_skill("strike", 100);

	set_skill("chuanyun-leg", 200);
	set_skill("kunlun-strike", 200);
	set_skill("liangyi-sword", 216);
	set_skill("taxue-wuhen",210);
	set_skill("xuantian-wuji",209);
	set_skill("zhentian-cuff",201);
	set_skill("xunlei-sword",216);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("parry", "liangyi-sword");
	map_skill("sword", "liangyi-sword");
	map_skill("leg","chuanyun-leg");
	map_skill("strike","kunlun-strike");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"skill" : (: do_skills :),
		"score" : (: do_score :),
		"�书"  : (: do_skills :),
	]));
	create_family("������",2, "����");
	setup();
        carry_object(__DIR__"rewj_sword")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
        carry_object(CLOTH_DIR"dao-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"�ԩ�������������������������������������������������������������\n"+
"�������� (chuanyun-leg)                    - ������� 200/    0\n"+
"  ����ȭ�� (cuff)                          - ƽ������ 100/    0\n"+
"  �����Ṧ (dodge)                         - ������� 200/    0\n"+
"  �����ڹ� (force)                         - ¯���� 212/    0\n"+
"  ������̸ (goplaying)                     - ����С�� 159/    0\n"+
"�������� (kunlun-strike)                   - ������� 200/    0\n"+
"  �����ȷ� (leg)                           - ƽ������ 100/    0\n"+
"�������ǽ��� (liangyi-sword)               - ¯���� 216/    0\n"+
"��̤ѩ�޺� (taxue-wuhen)                   - ¯���� 210/    0\n"+
"  ����д�� (literate)                      - �ڻ��ͨ 180/    0\n"+
"  �������� (luteplaying)                   - ����С�� 159/    0\n"+
"  �����м� (parry)                         - ������� 200/    0\n"+
"  �����Ʒ� (strike)                        - ƽ������ 100/    0\n"+
"  �������� (sword)                         - ¯���� 216/    0\n"+
"  ����ȭ�� (unarmed)                       - ������� 200/    0\n"+
"�������޼��� (xuantian-wuji)               - ������� 209/    0\n"+
"  Ѹ��ʮ���� (xunlei-sword)                - ¯���� 216/    0\n"+
"������ȭ�� (zhentian-cuff)                 - ������� 201/    0\n"+
"�ԩ�������������������������������������������������������������\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  596/  596 (100%)    �� �� �� ��    0 /    0 (+0)\n"+
"�� �� Ѫ ��  1210/  1210 (100%)    �� �� �� �� 3096 / 3096 (+0)\n"+
"�� ʳ �� ��    0/  300           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  300           �� �� �� ��  1016246\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"��ʵϰ���졿�����ɵڶ������ӡ��Ի�����ҫ�������ˡ�����(Rewj)\n"+
"\n"+
" ����һλ��ʮ����˸��µ��������࣬������һ��һ�ճ�ʱ��������\n"+
" ������[16/ 36]  ���ԣ�[31/ 49]   ���ǣ�[21/ 42]  ����[14/ 34]\n"+
" ������[ 14]  ��Ե��[ 20]  ��ʶ��[ 29]  ������[ 11]  ��ò��[ 15]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������    57936            ս��������   100818\n"+
" ս���˺���      230            ս��������        2\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 3795 ���ˣ������� 2 ����������ҡ�\n"+
" �㵽ĿǰΪֹ�ܹ����� 73 ���ˣ������� 68 ���Ƿ�����������\n"+
"\n"+
" ��    ����    47384     Ǳ    �ܣ� 5241 ( 98%)  ʵս���飺  1016246\n"+
" ��    ����       60     ����������    32366     ����������       30\n"+
"\n", this_object());
	return 1;
}
