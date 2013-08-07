// eagleg.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("��ӥ", ({ "eagleg"}));
	set("gender", "����");
	set("long","��̶��������֮һ���һ�����һ��������ʯ���Ƶķ�������
ӥ����������˫�ۣ���ʱ����������Ƶ�ɱ������������ÿ��
���ⶼ��ʾ������������������ƹ������ĵ���֮ħ��\n");
	set("title", HIW"ʥ��"NOR"�һ����ڶ�������");
	set("nickname", HIB"�����ӿ�"HIW"���޺�"NOR);
	set("age", 47);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 29);
	set("per", 26);
	set("int", 28);
	set("dex", 32);
	set("con", 36);
	set("str", 26);
	set("weiwang", 70);
	set("shen", 6217202);
	set("combat_exp", 5455577);
	set("PKS", 4);
	set("MKS", 6628);

	set("max_jing", 548);
	set("jing", 548);
	set("max_qi", 1501);
	set("qi", 1501);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3300);
	set("neili", 3300);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 206);
	set_skill("array", 250);
	set_skill("count", 250);
	set_skill("force", 253);
	set_skill("unarmed",250);
	set_skill("parry", 278);
	set_skill("dodge", 268);
	set_skill("sword", 250);
	set_skill("lanhua-shou", 375);
	set_skill("hand", 250);
	set_skill("hanbing-mianzhang", 372);
	set_skill("luoying-shenjian", 375);
	set_skill("qimen-wuxing", 102);
	set_skill("shenxing-baibian", 375);
	set_skill("tanzhi-shentong", 370);
	set_skill("yuxiao-jian", 376);
	set_skill("bibo-shengong", 204);
	set_skill("strike", 250);
	set_skill("luoying-zhang", 259);
        set_skill("xuanfeng-leg", 273);
        set_skill("finger", 250);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "yuxiao-jian");
	map_skill("finger", "tanzhi-shentong");
	map_skill("hand", "lanhua-shou");
	map_skill("sword", "yuxiao-jian");
	map_skill("unarmed","xuanfeng-leg");
	map_skill("strike","luoying-zhang");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("�һ���",2, "����");
	setup();
	carry_object(__DIR__"eagleg_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  ������ (array)                         - ��ɲ� 250/    0\n"+
"���̲��� (bibo-shengong)                 - ��ɲ� 204/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 268/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 253/    0\n"+
"  �������� (count)                         - ��ɲ� 250/    0\n"+
"  ����ָ�� (finger)                        - ��ɲ� 250/    0\n"+
"  �������� (hanbing-mianzhang)             - ��ɲ� 372/    0\n"+
"  �����ַ� (hand)                          - ��ɲ� 250/    0\n"+
"  ����д�� (literate)                      - ��Ȼ��� 206/    0\n"+
"  �����м� (parry)                         - ��ɲ� 278/    0\n"+
"��������Ѩ�� (lanhua-shou)                 - ��ɲ� 375/    0\n"+
"  ���аٱ� (shenxing-baibian)              - ��ͨƤë 375/    0\n"+
"  ��Ӣ�� (luoying-shenjian)              - ��ɲ� 375/    0\n"+
"  �������� (sword)                         - ��ɲ� 250/    0\n"+
"  ��Ӣ���� (luoying-zhang)               - ��ɲ� 259/    0\n"+
"  ����ȭ�� (unarmed)                       - �����뻯 250/    0\n"+
"  �������� (qimen-wuxing)                  - ������� 102/    0\n"+
"  �����Ʒ� (strike)                        - ��ɲ� 250/    0\n"+
"������ɨҶ�� (xuanfeng-leg)                - ��ɲ� 273/    0\n"+
"�����｣�� (yuxiao-jian)                   - ��ɲ� 376/    0\n"+
"����ָ��ͨ (tanzhi-shentong)               - ��ɲ� 370/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  548/  548 (100%)    �� �� �� ��    0 /    0 (+0)\n"+
"�� �� Ѫ �� 1501/ 1501 (100%)    �� �� �� �� 3300 / 3300 (+0)\n"+
"�� ʳ �� ��    0/  360           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  360           �� �� �� ��  5455577\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"������������ʥ�� �һ����ڶ������� ��ӥ(Eagleg)\n"+
"\n"+
" ����һλ��ʮ��������µ��������࣬����������ʮ����ʱ�Ŀ�����\n"+
" ������[ 51]  ���ԣ�[ 48]  ���ǣ�[ 61]  ����[ 58]\n"+
"\n"+
" ���ʦ���� ��ҩʦ��             ��û�д�\n"+
" ��İ����� ���ߡ�\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������   448204            ս��������  1045272\n"+
" ս���˺���       30            ս��������        1\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 6628 ���ˣ������� 4 ����������ҡ�\n"+
"\n"+
" ��    ����  6217202     Ǳ    �ܣ�   0 (100%)   ʵս���飺  5455577\n"+
" ��    ����       60     ����������      172     ����������       70\n"+
"\n", this_object());
	return 1;
}
