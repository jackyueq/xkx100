// fall.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("������", ({ "fall"}));
	set("gender", "Ů��");
	set("long","��̶�����ѧ�������������ּǡ������ߡ�����Ʒ��
���������վ��ת�أ��������ڡ�������Ϸ���ȿ��
�ڶ��ݵ���̶����������������ļ���������ϲ�ã�
Ҳ�����������ļ����Ͱ��������������������Ӱ��
��һ�����ƿ��������صİ�����ѩ�С�\n");
	set("title", HIY"����˶ʿ"HIG"���������Ž���"NOR"���̵���ʮ�������"NOR);
	set("nickname", HIM"������Ʒ�"NOR);
	set("age", 28);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 20);
	set("per", 30);
	set("int", 30);
	set("dex", 16);
	set("con", 17);
	set("str", 17);
	set("weiwang", 70);
	set("shen", 250000);
	set("combat_exp", 2717986);
	set("PKS", 0);
	set("MKS", 1011);

	set("max_jing", 540);
	set("jing", 540);
	set("max_qi", 1250);
	set("qi", 1250);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3300);
	set("neili", 3300);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 121);
	set_skill("force", 250);
	set_skill("unarmed",250);
	set_skill("parry", 250);
	set_skill("dodge", 250);
	set_skill("sword", 250);
	set_skill("cuff", 250);
	set_skill("qishang-quan", 200);
	set_skill("qiankun-danuoyi", 210);
	set_skill("jiuyang-shengong", 210);
	set_skill("shenghuo-ling", 200);
	set_skill("shenxing-baibian", 250);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "shenghuo-ling");
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
	carry_object(__DIR__"fall_sword")->wield();
	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  �������� (sword)                         - ��ɲ� 250/    0\n"+
"������ȭ (qishang-quan)                    - ��ɲ� 200/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 250/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 250/    0\n"+
"��ʥ���� (shenghuo-ling)                   - ��ɲ� 200/    0\n"+
"�������� (jiuyang-shengong)              - ��ɲ� 210/    0\n"+
"  ����д�� (literate)                      - ��Ȼ��� 121/    0\n"+
"  �����м� (parry)                         - ��ɲ� 250/    0\n"+
"�����аٱ� (shenxing-baibian)              - ��ɲ� 250/    0\n"+
"  ����ȭ�� (cuff)                          - ��ɲ� 250/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 250/    0\n"+
"��Ǭ����Ų�� (qiankun-danuoyi)             - ��ɲ� 210/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  540/  540 (100%)    �� �� �� ��    0 /    0 (+0)\n"+
"�� �� Ѫ �� 1250/ 1250 (100%)    �� �� �� �� 3300 / 3300 (+0)\n"+
"�� ʳ �� ��    0/  270           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  270           �� �� �� ��  2717986\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"������Ů��������˶ʿ���������Ž������̵���ʮ�������\������(fall)n"+
"\n"+
" ���ʦ���� ���޼ɡ�\n"+
" ��İ����� ���Ʒɡ�\n"+
"\n"+
" ����һλ��ʮ�����Ů�����࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 42]  ���ԣ�[ 42]  ���ǣ�[ 42]  ����[ 41]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������   400000            ս��������   500000\n"+
" ս���˺���       30            ս��������         1\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 1011 ���ˣ������� 0 ����������ҡ�\n"+
"\n"+
" ��    ����   250000     Ǳ    �ܣ�   0 (100%)   ʵս���飺  2717986\n"+
" ��    ����       60     ����������    12517     ����������       70\n"+
"\n", this_object());
	return 1;
}
