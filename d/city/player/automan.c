// automan.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("Ц����", ({ "automan"}));
	set("gender", "����");
	set("title", HIW"ʥ��"NOR"�䵱�ɵ��������ӡ�"HIC"�����ֻ� "HIR"�����©"NOR"��");
	set("nickname", HIY"�����г��зֶ����"NOR);
	set("long", "��̶���зֶ����������Ľ�����µ�һ��������ת���ƾ���
Ψһ���ˣ��ԡ��Ա�֮������ʩ�����������¡����������䵱�ɣ�
��Ϊһ����Ϊ��֪��С��ʿ�������ֵĳ��֮�������𾪡�\n");
	set("age", 25);
	set("class", "swordman");
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 30);
	set("dex", 20);
	set("con", 25);
	set("str", 21);
	set("weiwang", 90);
	set("shen", 270000);
	set("combat_exp", 4953266);
	set("PKS", 23);
	set("MKS", 16424);
	set("max_jing", 485);
	set("jing", 485);
	set("max_qi", 2553);
	set("qi", 2553);
	set("max_jingli", 180);
	set("jingli", 180);
	set("max_neili", 3050);
	set("neili", 3050);
	set("meili", 60);
	set("score", 36534);
	set("env/no_teach", "1");

	set_skill("claw", 250);
	set_skill("cuff", 250);
	set_skill("dodge", 301);
	set_skill("douzhuan-xingyi", 150);
	set_skill("finger", 250);
	set_skill("force", 319);
	set_skill("hand", 250);
	set_skill("jiuyin-baiguzhao", 230);
	set_skill("literate", 296);
	set_skill("murong-sword", 201);
	set_skill("parry", 250);
	set_skill("strike", 250);
	set_skill("sword", 330);
	set_skill("liangyi-jian", 345);
	set_skill("taiji-jian", 360);
	set_skill("taiji-quan", 200);
	set_skill("taiji-shengong", 299);
	set_skill("tiyunzong", 259);
	set_skill("taoism", 150);
	set_skill("unarmed", 250);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "liangyi-jian");
	map_skill("unarmed", "taiji-quan");
	map_skill("claw", "jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"skill" : (: do_skills :),
		"score" : (: do_score :),
		"�书"  : (: do_skills :),
	]));

	create_family("�䵱��", 3, "����");
	setup();
	carry_object(__DIR__"automan_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"�ԩ�������������������������������������������������������������\n"+
"  ����צ�� (claw)                          - ��ɲ� 250/    0\n"+
"  ����ȭ�� (cuff)                          - ��ɲ� 250/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 301/56468\n"+
"  ��ת���� (douzhuan-xingyi)               - ��Ȼ���� 150/    0\n"+
"  ����ָ�� (finger)                        - ��ɲ� 250/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 319/31356\n"+
"  �����ַ� (hand)                          - ��ɲ� 250/    0\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - ��ɲ� 230/   59\n"+
"�����ǽ��� (liangyi-jian)                  - ��ɲ� 345/55463\n"+
"  ����д�� (literate)                      - ��ɲ� 296/    0\n"+
"  Ľ�ݽ��� (murong-sword)                  - ��ɲ� 201/    3\n"+
"  �����м� (parry)                         - ��ɲ� 250/    0\n"+
"  �����Ʒ� (strike)                        - ��ɲ� 250/    0\n"+
"  �������� (sword)                         - ��ɲ� 330/    1\n"+
"��̫������ (taiji-jian)                    - ��ɲ� 360/ 1415\n"+
"��̫��ȭ (taiji-quan)                      - ��ɲ� 200/    2\n"+
"��̫���� (taiji-shengong)                - ��ɲ� 299/   37\n"+
"  ��ѧ�ķ� (taoism)                        - ��Ȼ���� 150/    0\n"+
"�������� (tiyunzong)                       - ��ɲ� 259/ 3287\n"+
"  ����ȭ�� (unamred)                       - ��ɲ� 250/    0\n"+
"�ԩ�������������������������������������������������������������\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  485/  850 (100%)    �� �� �� ��  180 /  180 (+0)\n"+
"�� �� Ѫ �� 2553/ 2553 (100%)    �� �� �� �� 3050 / 3050 (+0)\n"+
"�� ʳ �� ��    0/  300           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  300           �� �� �� ��  4953266\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"�� �������� ��ʥ���䵱�ɵ��������ӡ������ֻ� �����©��Ц����(Automan)\n"+
" ����һλ��ʮ��������µ��������࣬����������ʮ���ճ�ʱ��������\n"+
" ������[21/46 ]  ���ԣ�[30/ 59 ]   ���ǣ�[25/ 56]  ����[20/ 50]\n"+
" ���ʦ���� ��Զ�š�             ����ʮ�����ƽ�ʮ��������ʮ����ͭǮ��\n"+
" �㻹�Ǹ������\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
"ս��������   302190         ս��������   502991\n"+
"ս���˺���   200            ս��������   2 \n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 16424 ���ˣ������� 23 ����������ҡ�\n"+
" �㵽ĿǰΪֹ�ܹ����� 7 ���ˣ������� 3 ���Ƿ�����������\n"+
"\n"+
" ��    ����   270000     Ǳ    �ܣ� 0  ( 100%)    ʵս���飺   4953266\n"+
" ��    ����       60     ����������     36534     ����������        90\n"+
"\n", this_object());
	return 1;
}
