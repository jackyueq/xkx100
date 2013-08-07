// laughing.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("ЦЦ��", ({ "laughing"}));
	set("gender", "����");
	set("long","����һλ����������������Щ������ؤ�������������
������һ�������ܵУ�������ȴ����������������Ұ��
���˼����ġ������������������Ǻ�ǿ����ȴʱ������
�������������ɢ���ŵ�΢Ц��\n"); 
	set("title", HIW"ʥ��"NOR"��ͨ����"NOR);
	set("nickname", HIB"����С��"HIG"������"NOR);
	set("age", 45);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 10);
	set("per", 27);
	set("int", 30);
	set("dex", 16);
	set("con", 14);
	set("str", 20);
	set("weiwang", 70);
	set("shen", 0);
	set("combat_exp", 6238756);
	set("PKS", 0);
	set("MKS", 3107);

	set("max_jing", 700);
	set("jing", 700);
	set("max_qi", 1500);
	set("qi", 1500);
	set("max_jingli", 500);
	set("jingli", 500);
	set("max_neili", 3900);
	set("neili", 3900);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 210);
	set_skill("taoism", 100);
	set_skill("force", 260);
	set_skill("unarmed",265);
	set_skill("parry", 260);
	set_skill("dodge", 260);
	set_skill("blade", 250);
	set_skill("staff", 250);
	set_skill("xianglong-zhang", 380);
	set_skill("lingboweibu", 380);
	set_skill("huntian-qigong", 260);
	set_skill("kuangfeng-blade", 380);
	set_skill("dagou-bang", 380);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "xianglong-zhang");
	map_skill("blade", "kuangfeng-blade");
	map_skill("unarmed","xianglong-zhang");
	map_skill("staff","dagou-bang");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("ؤ��",18, "����");
	setup();
	carry_object(__DIR__"laughing_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  �������� (blade)                         - ��ɲ� 250/    0\n"+
"���򹷰��� (dagou-bang)                    - ��ɲ� 380/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 260/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 260/    0\n"+
"����絶   (kuangfeng-blade)               - ��ɲ� 380/    0\n"+
"���������� (huntian-qigong)                - ��ɲ� 260/    0\n"+
"  ����д�� (literate)                      - ��ɲ� 210/    0\n"+
"  �����м� (parry)                         - ��ɲ� 260/    0\n"+
"���貨΢�� (lingboweibu)                   - ��ɲ� 380/    0\n"+
"  �����ȷ� (staff)                         - ��ɲ� 250/    0\n"+
"  ��ѧ�ķ� (taoism)                        - ������� 100/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 265/    0\n"+
"������ʮ���� (xianglong-zhang)             - ��ɲ� 380/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  700/  700 (100%)    �� �� �� ��  500 /  500 (+0)\n"+
"�� �� Ѫ �� 1500/ 1500 (100%)    �� �� �� �� 3900 / 3900 (+0)\n"+
"�� ʳ �� ��    0/  300           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  300           �� �� �� ��  6238756\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"������������ʥ����ͨ���ա�����С�ŷ����䡹ЦЦ��(Laughing)\n"+
"\n"+
" ����һλ��ʮ������������࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 46]  ���ԣ�[ 51]  ���ǣ�[ 40]  ����[ 42]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������   800000            ս��������   1000000\n"+
" ս���˺���       30            ս��������         1\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 3107 ���ˣ������� 0 ����������ҡ�\n"+
"\n"+
" ��    ����        0     Ǳ    �ܣ�   0 (100%)   ʵս���飺  6238756\n"+
" ��    ����       60     �ۺ����ۣ�        0     ����������       70\n"+
"\n", this_object());
	return 1;
}
