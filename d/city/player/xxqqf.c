// xxqqf.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("��׼����", ({ "xxqqf"}));
	set("gender", "����");
	set("long","�һ������ӣ�ʦ�ӻ���а��������ճɱ�̶�������𡣿�
����������Я��������Զ�������ʢʱ��������ԭ��ƾ
�豾�ž�����������Ѩ���͡������������������һ����
����һ����в��ۣ���Ȼ�����һ�����Ǳ����ѧ������
�����������뷢�԰ף���ɫ��Щ������Ȼ���в�ʱ�ӹ�һ
˿��â�������µ�����׹����ʡ�\n");
	set("title", HIW"ʥ��"NOR"����������"NOR);
	set("nickname", HIR"��"HIG"��һ��"HIB"��"NOR);
	set("age", 79);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 27);
	set("int", 30);
	set("dex", 18);
	set("con", 21);
	set("str", 20);
	set("weiwang", 30);
	set("shen", 10819664);
	set("combat_exp", 12129747);
	set("PKS", 28);
	set("MKS", 29859);

	set("max_jing", 485);
	set("jing", 485);
	set("max_qi", 1353);
	set("qi", 1353);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 4050);
	set("neili", 4050);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 201);
	set_skill("force", 290);
	set_skill("unarmed",250);
	set_skill("parry", 300);
	set_skill("dodge", 251);
	set_skill("sword", 270);
	set_skill("cuff", 250);
        set_skill("array",233);
        set_skill("bibo-shengong",260);
        set_skill("blade",250);
        set_skill("claw",250);
        set_skill("count",103);
        set_skill("finger",250);
        set_skill("hand",250);
        set_skill("jiuyin-baiguzhao",270);
        set_skill("kuangfeng-blade",182);
        set_skill("lanhua-shou",444);
        set_skill("lingboweibu",50);
        set_skill("luoying-zhang",443);
        set_skill("qimen-wuxing",51);
        set_skill("shenxing-baibian",375);
        set_skill("strike",250);
        set_skill("taixuan-gong",248);
        set_skill("tanzhi-shentong",369);
        set_skill("xuanfeng-leg",427);
        set_skill("yuxiao-jian",444);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "lanhua-shou");
	map_skill("sword", "yuxiao-jian");
	map_skill("unarmed","xuanfeng-leg");
	map_skill("hand","lanhua-shou");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("�һ���",3, "����");
	setup();
	carry_object(__DIR__"xxqqf_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  ��Ӱ���� (anying-fuxiang)                - ��ɲ� 340/  303\n"+
"  ������ (array)                         - ��ɲ� 233/12605\n"+
"���̲��� (bibo-shengong)                 - ��ɲ� 260/13541\n"+
"  �������� (blade)                         - ��ɲ� 250/    0\n"+
"  ����צ�� (claw)                          - ��ɲ� 250/    0\n"+
"  �������� (count)                         - ������� 103/  283\n"+
"  ����ȭ�� (cuff)                          - ��ɲ� 250/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 251/ 3268\n"+
"  ����ָ�� (finger)                        - ��ɲ� 250/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 290/29861\n"+
"  �����ַ� (hand)                          - ��ɲ� 250/    5\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - ��ɲ� 270/   59\n"+
"����絶�� (kuangfeng-blade)               - һ����ʦ 182/27564\n"+
"��������Ѩ�� (lanhua-shou)                 - ������ʥ 444/78267\n"+
"  �貨΢�� (lingboweibu)                   - ��������  50/  380\n"+
"  ����д�� (literate)                      - ��ɲ� 201/    0\n"+
"����Ӣ���� (luoying-zhang)               - ������ʥ 443/117000\n"+
"  �����м� (parry)                         - ��ɲ� 300/76467\n"+
"  �������� (qimen-wuxing)                  - ��֪һ��  51/  861\n"+
"�����аٱ� (shenxing-baibian)              - ��ɲ� 375/10342\n"+
"  �����Ʒ� (strike)                        - ��ɲ� 250/    0\n"+
"  �������� (sword)                         - ��ɲ� 270/    1\n"+
"  ̫���� (taixuan-gong)                    - ��ɲ� 248/    0\n"+
"����ָ��ͨ (tanzhi-shentong)               - ��ɲ� 369/93330\n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 250/    0\n"+
"������ɨҶ�� (xuanfeng-leg)                - ������ʥ 427/   14\n"+
"�����｣�� (yuxiao-jian)                   - ������ʥ 444/37462\n", this_object());
	return 1;
}
int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  485/  485 (100%)   �� �� �� ��    0 /    0 (+0)\n"+
"�� �� Ѫ �� 1353/ 1353 (100%)   �� �� �� �� 4050 / 4050 (+0)\n"+
"�� ʳ �� ��  222/  280          �� Ǳ �� ��  49584\n"+
"�� �� ˮ ��  225/  280          �� �� �� ��  12129747\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"������������ʥ�������������һ������������ӡ�����һ���꡹��׼����(Xxqqf)\n"+
"\n"+
" ����һλ��ʮ����ʮ�����µ��������࣬��������¶�ʮ���ճ�ʱһ������\n"+
" ������[ 18]  ���ԣ�[ 30]  ���ǣ�[ 21]  ����[ 24]\n"+
"\n"+
" ���ʦ����½�˷硣             ��ʮ������ǧ�����ʮ���ƽ�\n"+
" �㻹�Ǹ������\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս��������   317578            ս��������   860038\n"+
" ս���˺���      260            ս��������        1\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 29860 ���ˣ������� 28 ����������ҡ�\n"+
" �㵽ĿǰΪֹ�ܹ����� 5 ���ˣ������� -1 ���Ƿ�����������\n"+
"\n"+
" ��    ���� 10820830     Ǳ    �ܣ� 49612 ( 95%)         ʵս���飺 12130073\n"+
" ��    ����       60     ����������    43898     ����������       30\n"+
"\n", this_object());
	return 1;
}

