// luoyz.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("����", ({ "luoyz"}));
	set("gender", "����");
        set("long","��̶��������֮һ�����������֣������������޾С�
���Է����ѧ��ʮ����˼����������������쳾��
�飬���������������ڣ���������������\n");
	set("nickname", HIR"�ϲ���, ����Ƥ"NOR);
	set("title", HIR"ѧʿ"NOR"�����ɵ���ʮ�������");
	set("age", 66);
	set("class", "bonze");
	set("attitude", "friendly");

	set("kar", 28);
	set("per", 28);
	set("int", 24);
	set("dex", 22);
	set("con", 23);
	set("str", 17);
	set("score", 144);
	set("weiwang", 70);
	set("shen", -17879);
	set("combat_exp", 2692981);
	set("PKS", 2);
	set("MKS", 1894);

	set("max_jing", 1054);
	set("jing", 1054);
	set("max_qi", 1301);
	set("qi", 1301);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3143);
	set("neili", 3143);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("buddhism", 180);
	set_skill("claw", 242);
	set_skill("club", 250);
	set_skill("cuff", 180);
	set_skill("damo-jian", 223);
	set_skill("dodge", 250);
	set_skill("finger", 250);
	set_skill("force", 250);
	set_skill("hand", 180);
	set_skill("hunyuan-yiqi", 101);
	set_skill("jingang-quan", 156);
	set_skill("jiuyin-baiguzhao", 214);
	set_skill("kongming-quan", 250);
	set_skill("literate", 160);
	set_skill("nianhua-zhi", 155);
	set_skill("parry", 250);
	set_skill("qianye-shou", 174);
	set_skill("riyue-bian", 232);
	set_skill("shaolin-shenfa", 257);
	set_skill("sword", 191);
	set_skill("unarmed", 250);
	set_skill("whip", 180);
	set_skill("xuantian-zhi", 242);
	set_skill("yijinjing", 201);
	set_skill("yizhi-chan", 250);
	set_skill("zui-gun", 279);

	map_skill("unarmed", "kongming-quan");
	map_skill("sword", "damo-jian");
	map_skill("force", "yijinjing");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "zui-gun");
	map_skill("whip", "riyue-bian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("club", "zui-gun");
	map_skill("finger", "yizhi-chan");
	map_skill("dodge", "shaolin-shenfa");
	prepare_skill("claw", "jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("������",4, "����");
	setup();
	carry_object(__DIR__"luoyz_club")->wield();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
        carry_object(CLOTH_DIR"seng-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"�ԩ�������������������������������������������������������������\n"+
"  �����ķ� (buddhism)                      - ������ 180/    0\n"+
"  ����צ�� (claw)                          - ��ɲ� 242/    0\n"+
"  �������� (club)                          - ��ɲ� 250/    0\n"+
"  ����ȭ�� (cuff)                          - һ����ʦ 180/    0\n"+
"����Ħ�� (damo-jian)                       - ��ɲ� 223/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 250/    0\n"+
"  ����ָ�� (finger)                        - ��ɲ� 250/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 250/    0\n"+
"  �����ַ� (hand)                          - һ����ʦ 180/    0\n"+
"  ��Ԫһ���� (hunyuan-yiqi)                - ������� 101/    0\n"+
"������ȭ (jingang-quan)                  - �����뻯 156/    0\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - ��ɲ� 214/    0\n"+
"������ȭ (kongming-quan)                   - ��ɲ� 250/    0\n"+
"  ����д�� (literate)                      - ������˫ 160/    0\n"+
"  �黨ָ (nianhua-zhi)                     - �����뻯 155/    0\n"+
"  �����м� (parry)                         - ��ɲ� 250/    0\n"+
"  ����ǧҶ�� (qianye-shou)                 - �Ƿ��켫 174/    0\n"+
"�����±޷� (riyue-bian)                    - ��ɲ� 232/    0\n"+
"�������� (shaolin-shenfa)                - ��ɲ� 257/    0\n"+
"  �������� (sword)                         - һ����ʦ 191/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 250/    0\n"+
"  �����޷� (whip)                          - һ����ʦ 180/    0\n"+
"  ��������ָ (xuantian-zhi)                - ��ɲ� 242/    0\n"+
"���׽�� (yijinjing)                   - ��ɲ� 201/    0\n"+
"��һָ�� (yizhi-chan)                      - ��ɲ� 250/    0\n"+
"��������� (zui-gun)                       - ��ɲ� 279/    0\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� �� 1054/ 1054 (100%)    �� �� �� ��    0 /    0 (+0)\n"+
"�� �� Ѫ �� 1301/ 1301 (100%)    �� �� �� �� 3143 / 3143 (+0)\n"+
"�� ʳ �� ��    0/  270           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  270           �� �� �� ��  2692981\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"�� ��  �� ��ѧʿ�����ɵ���ʮ������ӡ��ϲ���,����Ƥ������(Luoyz)\n"+
"\n"+
" ����һλ��ʮ������������࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 42]  ���ԣ�[ 40]  ���ǣ�[ 48]  ����[ 47]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������   343895            ս��������   705361\n"+
" ս���˺���       30            ս��������        1\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 1896 ���ˣ������� 2 ����������ҡ�\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ����� 0 ���ˣ������� 0 ���Ƿ�����������\n"+
"\n"+
" ��    ����   -17879     Ǳ    �ܣ�   0 (100%)   ʵս���飺  2692981\n"+
" ��    ����       60     ����������      144     ����������       70\n"+
"\n", this_object());
	return 1;
}


