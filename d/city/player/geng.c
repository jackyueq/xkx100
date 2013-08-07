// geng.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("����С����", ({ "geng"}));
	set("gender", "����");
	set("long","��̶������ң����������֡�����������ѧ���಻�ܳ���
���ơ���ƹŷ𣬼��˺������㣻ľ��ͭ�죬����һ����
����������һ����֪����Զ�ڰ��մ�Į�������ֳ�ɽ����
�ɰ������߽�������������׳ʿҲ��\n");
	set("title", HIY"����˶ʿ"HIG"���̷����Ž���"NOR"�����ɵ���ʮ�������");
	set("nickname", HIC"���Ĵ��ܲ�"NOR);
	set("age", 42);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 22);
	set("per", 26);
	set("int", 19);
	set("dex", 20);
	set("con", 20);
	set("str", 24);
	set("weiwang", 70);
	set("shen", 0);
	set("combat_exp", 2404210);
	set("PKS", 3);
	set("MKS", 1437);

	set("max_jing", 1004);
	set("jing", 1004);
	set("max_qi", 1251);
	set("qi", 1251);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3260);
	set("neili", 3260);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 121);
	set_skill("buddhism", 120);
	set_skill("club", 250);
	set_skill("claw",250);
	set_skill("force", 251);
	set_skill("unarmed",250);
	set_skill("parry", 255);
	set_skill("dodge", 250);
	set_skill("sword", 250);
	set_skill("blade", 250);
	set_skill("damo-jian", 219);
	set_skill("finger", 250);
	set_skill("fumo-jian", 260);
	set_skill("hunyuan-yiqi", 250);
	set_skill("jingang-quan", 203);
	set_skill("kongming-quan", 244);
	set_skill("lingboweibu", 268);
	set_skill("nianhua-zhi", 100);
	set_skill("qianye-shou", 110);
	set_skill("sanhua-zhang", 101);
	set_skill("sougu", 271);
	set_skill("strike", 250);
	set_skill("wuyun-jian", 265);
	set_skill("xiuluo-dao", 140);
	set_skill("yijinjing", 201);
	set_skill("zui-gun", 282);
	set_skill("qianye-shou", 110);
	set_skill("hand", 250);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "zui-gun");
	map_skill("sword", "damo-jian");
	map_skill("unarmed","kongming-quan");
	map_skill("club","zui-gun");
	map_skill("finger","nianhua-zhi");
	map_skill("strike","sanhua-zhang");
	map_skill("claw","sougu");
	map_skill("blade","xiuluo-dao");
        map_skill("hand","hand");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("������",35, "����");
	setup();
	carry_object(__DIR__"geng_sword")->wield();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
        carry_object(CLOTH_DIR"seng-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  �������� (blade)                         - ��ɲ� 250/    0\n"+
"  �����ķ� (buddhism)                      - ��Ȼ��� 120/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 250/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 251/    0\n"+
"  �������� (club)                          - ��ɲ� 250/    0\n"+
"����Ħ�� (damo-jian)                       - ��ɲ� 219/    0\n"+
"  ����ָ�� (finger)                        - ��ɲ� 250/    0\n"+
"������ȭ (kongming-quan)                   - ��ɲ� 244/    0\n"+
"  ����д�� (literate)                      - ��Ȼ��� 121/    0\n"+
"  �����м� (parry)                         - ��ɲ� 255/    0\n"+
"  ��Ħ�� (fumo-jian)                       - ��ɲ� 260/    0\n"+
"  ��Ԫһ���� (hunyuan-yiqi)                - ��ɲ� 200/    0\n"+
"������ȭ (jingang-quan)                  - ��ɲ� 203/    0\n"+
"  �������� (sword)                         - ��ɲ� 250/    0\n"+
"���黨ָ (nianhua-zhi)                     - ������� 100/    0\n"+
"  ����ȭ�� (unarmed)                       - �����뻯 250/    0\n"+
"������ǧҶ�� (qianye-shou)                 - ������� 110/    0\n"+
"��ɢ���� (sanhua-zhang)                    - ������� 101/    0\n"+
"  �����Ʒ� (strike)                        - ��ɲ� 250/    0\n"+
"  �����ַ� (hand)                          - ��ɲ� 250/    0\n"+
"  ����צ�� (claw)                          - ��ɲ� 250/    0\n"+
"���׽�� (yijinjing)                   - ��ɲ� 201/    0\n"+
"��������� (zui-gun)                       - ��ɲ� 282/    0\n"+
"  �������ҽ� (wuyun-jian)                  - ��ɲ� 265/    0\n"+
"�����޵� (xiuluo-dao)                      - �����뻯 140/    0\n"+
"���ѹ�ӥצ�� (sougu)                       - ��ɲ� 271/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� �� 1004/ 1004 (100%)    �� �� �� ��    0 /   0 (+0)\n"+
"�� �� Ѫ �� 1251/ 1251 (100%)    �� �� �� �� 3260 / 3260 (+0)\n"+
"�� ʳ �� ��    0/  340           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  340           �� �� �� ��  2404210\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"�� ʥ  ɮ ������˶ʿ���̷����Ž��������ɵ���ʮ������ӡ����Ĵ��ܲ�������С����(Geng)\n"+
"\n"+
" ����һλ��ʮ���������µ��������࣬������ʮ�������պ�ʱ��������\n"+
" ������[ 49]  ���ԣ�[ 31]  ���ǣ�[ 46]  ����[ 42]\n"+
"\n"+
" ���ʦ���Ǵ�Ħ���档             ��û�д�\n"+
" �㻹�Ǹ������\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������   450000            ս��������   880000\n"+
" ս���˺���       30            ս��������        1\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 1437 ���ˣ������� 3 ����������ҡ�\n"+
"\n"+
" ��    ����        0     Ǳ    �ܣ� 112 ( 99%)   ʵս���飺  2404210\n"+
" ��    ����       60     ����������       54     ����������       70\n"+
"\n", this_object());
	return 1;
}
