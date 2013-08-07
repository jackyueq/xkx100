// top.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("���", ({ "top"}));
	set("gender", "����");
	set("long","ѩɽ�ɵ��ӣ��츳����������ʱֻ��һ��Զ������Ͷʦѩɽ��
�̶����꼴���������¡��������˼����ģ���ѧ����һ��ǧ�
ĳ�괺ů����֮�ʣ�ǣ�����������������һλ��ѩ���ˣ���
�����ã����Ϊ���ޣ��Ӵ˵������������꿪����ң�ţ�������
ͽ���ڣ������ֵ�һ����Ҳ����������ף����ް߰ף����ϼ���
��������ƣ����Թµ���Ŀ�⣬ǡ������ʱƬƬ��ҶƮ��Ĳ�ɣ��\n");
	set("title", HIW"ʥ��"NOR"��ң������"NOR);
	set("nickname", HIY"��"HIR" ��"HIG" ��"HIB" ��"NOR);
	set("age", 56);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 26);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	set("shen", 1744183791);
	set("combat_exp", 9138500);
	set("PKS", 19);
	set("MKS", 11831);

	set("max_jing", 522);
	set("jing", 522);
	set("max_qi", 3011);
	set("qi", 3011);
	set("max_jingli", 154);
	set("jingli", 154);
	set("max_neili", 5002);
	set("neili", 5002);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 272);
	set_skill("force", 290);
	set_skill("parry", 382);
	set_skill("dodge", 320);
	set_skill("sword", 303);
	set_skill("cuff", 298);
        set_skill("houquan",440);
        set_skill("dashou-yin",400);
        set_skill("blade",339);
        set_skill("claw",298);
        set_skill("hubo",138);
        set_skill("huoyan-dao",435);
        set_skill("hand",298);
        set_skill("hammer",298);
        set_skill("liangyi-jian",428);
        set_skill("mingwang-jian",419);
        set_skill("necromancy",198);
        set_skill("qiankun-danuoyi",248);
        set_skill("qiufeng-chenfa",424);
        set_skill("riyue-lun",423);
        set_skill("shenxing-baibian",429);
        set_skill("strike",298);
        set_skill("taiji-jian",415);
        set_skill("taiji-quan",330);
        set_skill("taiji-shengong",332);
        set_skill("taoism",150);
        set_skill("unarmed",311);
        set_skill("wuhu-duanmendao",201);
        set_skill("xue-dao",438);
        set_skill("yujiamu-quan",400);
        set_skill("taixuan-gong",278);

	map_skill("unarmed", "houquan");
	map_skill("hand", "dashou-yin");
	map_skill("sword", "liangyi-jian");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("force", "taiji-shengong");
	map_skill("cuff", "yujiamu-quan");
	map_skill("parry", "taiji-jian");
	map_skill("whip", "qiufeng-chenfa");
	map_skill("claw", "jiuyin-baiguzhao");
	map_skill("strike", "huoyan-dao");
	map_skill("dodge", "shenxingbaibian");
	map_skill("hammer", "riyue-lun");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("ѩɽ��",6, "����");
	setup();
	carry_object(__DIR__"top_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"  �������� (blade)                         - ��ɲ� 339/   44\n"+
"  ����צ�� (claw)                          - ��ɲ� 298/   12\n"+
"  ����ȭ�� (cuff)                          - ��ɲ� 298/    1\n"+
"�����ڴ���ӡ (dashou-yin)                  - ������ʥ 400/18380\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 320/51443\n"+
"  �����ڹ� (force)                         - ��ɲ� 352/13145\n"+
"  �������� (hammer)                        - ��ɲ� 298/   21\n"+
"  �����ַ� (hand)                          - ��ɲ� 298/    2\n"+
"����ȭ (houquan)                           - ������ʥ 440/71026\n"+
"  ���һ��� (hubo)                          - ��Ȼ��� 138/    0\n"+
"�����浶 (huoyan-dao)                      - ������ʥ 435/  195\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - ��ɲ� 211/    0\n"+
"�����ǽ��� (liangyi-jian)                  - ������ʥ 428/    1\n"+
"  ����д�� (literate)                      - ��ɲ� 272/ 1583\n"+
"  ���������� (mingwang-jian)               - ������ʥ 419/    0\n"+
"  ������ (necromancy)                      - һ����ʦ 198/  106\n"+
"  �����м� (parry)                         - ��ɲ� 382/40526\n"+
"  Ǭ����Ų�� (qiankun-danuoyi)             - ��ɲ� 248/    0\n"+
"�������� (qiufeng-chenfa)                - ������ʥ 424/32382\n"+
"�������ַ� (riyue-lun)                     - ������ʥ 423/84670\n"+
"�����аٱ� (shenxing-baibian)              - ������ʥ 429/ 6500\n"+
"  �����Ʒ� (strike)                        - ��ɲ� 298/    0\n"+
"  �������� (sword)                         - ��ɲ� 303/   69\n"+
"��̫������ (taiji-jian)                    - ������ʥ 415/134233\n"+
"  ̫��ȭ (taiji-quan)                      - ��ɲ� 330/  193\n"+
"��̫���� (taiji-shengong)                - ��ɲ� 332/18089\n"+
"  ̫���� (taixuan-gong)                    - ��ɲ� 278/37811\n"+
"  ��ѧ�ķ� (taoism)                        - ��Ȼ��ͨ 150/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 311/26426\n"+
"���廢���ŵ� (wuhu-duanmendao)             - ��ɲ� 201/ 2312\n"+
"  Ѫ������ (xue-dao)                       - ������ʥ 438/48464\n"+
"��������ĸȭ (yujiamu-quan)              - ������ʥ 400/62140\n", this_object());
	return 1;
}
int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  522/  522 (100%)   �� �� �� ��  154 /  154 (+0)\n"+
"�� �� Ѫ �� 3011/ 3011 (100%)   �� �� �� �� 5002 / 5002 (+0)\n"+
"�� ʳ �� ��  191/  360          �� Ǳ �� ��  19\n"+
"�� �� ˮ ��  150/  360          �� �� �� ��  9138500\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"������������ʥ����ң������ѩɽ���׼ҵ��ӡ��� �� �� �ա����(Top)\n"+
"\n"+
" ����һλ��ʮ����Ÿ��µ��������࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 57]  ���ԣ�[ 51]  ���ǣ�[ 46]  ����[ 56]\n"+
"\n"+
" ���ʦ���� ���ײ���             ����ǧ��ʮ�����ƽ�\n"+
" �㻹�Ǹ������\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 11831 ���ˣ������� 19 ����������ҡ�\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ����� 41 ���ˣ������� 29 ���Ƿ�����������\n"+
"\n"+
" ��    ���� 1744183791   Ǳ    �ܣ�  19 ( 99%)   ʵս���飺  9138500\n"+
" ��    ����       60     ����������   345593     ����������       80\n"+
"\n", this_object());
	return 1;
}

