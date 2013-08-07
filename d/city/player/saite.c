// saite.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
int do_noodle();
int do_linqiyan();
int do_baoer();
int do_yuki();
int do_ftlsk();
void create()
{
	set_name("����", ({ "saite"}));
	set("gender", "����");
	set("long","��2001��Ӵ�xkx100������һֱ���������ʵӵ���ߡ��Ӵ���
���ﳣ���ܿ���������Ӱ�����������������������ܵ�����
�ҵ�ϲ������ϧ����δ��һ����֪��������һ������а��飬
��ͬ������̶��Ȥ���������ĺܶ�id����kofc ssread�ȶ���
����ȡ�����������Ρ���̶���ڶԱ�д�����˼����Բ���Ũ
����Ȥ�����ɴ˷��ֲ��ٴ�Сbug�������̶������Ϥ�����˷�
ʥ�ͣ���������ղ��ý⣬��Ϊ���£���ң��ȥ��\n");
	set("title", NOR"��ң�ɵ���������"NOR);
	set("nickname", HIC"�Ҿ�ֻ�ܵ������ǰ�.."NOR);
	set("age", 34);
	set("class", "swordman");
	set("attitude", "friendly");

	set("kar", 20);
	set("per", 30);
	set("int", 37);
	set("dex", 40);
	set("con", 35);
	set("str", 40);
	set("weiwang", 50);
	set("shen", -802282);
	set("combat_exp", 1691661);
	set("PKS", 2);
	set("MKS", 7449);

	set("max_jing", 570);
	set("jing", 570);
	set("max_qi", 982);
	set("qi", 982);
	set("max_jingli", 600);
	set("jingli", 600);
	set("max_neili", 8130);
	set("neili", 8130);
	set("meili", 60);

	set_skill("literate", 175);
	set_skill("taoism", 120);
	set_skill("force", 200);
	set_skill("unarmed",100);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("construction", 10);
	set_skill("hubo", 200);
	set_skill("qimen-wuxing", 101);
	set_skill("claw", 151);
	set_skill("sword", 601);
	set_skill("training", 39);
	set("env/no_teach", "1");

	set_skill("shenzhao-jing", 157);
	set_skill("jinshe-jian", 200);
	set_skill("jinshe-zhui", 200);
	set_skill("jiuyin-baiguzhao", 171);
	set_skill("beiming-shengong", 200);
	set_skill("kongming-quan", 1);
	set_skill("lingboweibu", 204);
	set_skill("tianyu-qijian", 202);
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "tianyu-qijian");
	map_skill("throwing", "jinshe-zhui");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("sword","tianyu-qijian");
	prepare_skill("claw","jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"noodle"  : (: do_noodle :),
		"linqiyan": (: do_linqiyan :),	
		"yuki"	: (: do_yuki :),
		"baoer" : (: do_baoer :),
		"ftlsk" : (: do_ftlsk :),
	]));

	create_family("��ң��",2, "����");
	setup();
//	carry_object(__DIR__"saite_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
    carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+

"�ԩ�������������������������������������������������������������������\n"+
"  ��ڤ�� (beiming-shengong)              - ������� 200/  173\n"+
"  ����צ�� (claw)                          - ����С�� 151/  163\n"+
"  ��ľ���� (construction)                  - ��ѧէ��  10/   48\n"+
"  �����Ṧ (dodge)                         - ������� 200/  198\n"+
"  �����ڹ� (force)                         - ������� 200/   31\n"+
"  ���һ��� (hubo)                          - �������� 100/    0\n"+
"  ���߽��� (jinshe-jian)                   - ������� 200/  527\n"+
"������׶�� (jinshe-zhui)                   - ������� 200/    8\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - ������� 171/14648\n"+
"  ����ȭ (kongming-quan)                   - ����һ��   1/    0\n"+
"���貨΢�� (lingboweibu)                   - ������� 204/41847\n"+
"  ����д�� (literate)                      - ����С�� 175/ 3851\n"+
"  �����м� (parry)                         - ������� 200/ 1119\n"+
"  �������� (qimen-wuxing)                  - �������� 101/    0\n"+
"�����վ� (shenzhao-jing)                   - ����С�� 157/17362\n"+
"  �������� (sword)                         - ������� 201/ 1413\n"+
"  ��ѧ�ķ� (taoism)                        - ������ 120/  314\n"+
"�������潣 (tianyu-qijian)                 - ������� 202/ 6566\n"+
"  Ԧ���� (training)                        - �����ž�  39/  828\n"+
"  ����ȭ�� (unarmed)                       - ƽ������ 100/   22\n"+
"�ԩ�������������������������������������������������������������������\n", this_object());
	return 1;
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  570/  570 (100��)   �� �� �� ��  600 /  600 (+0)\n"+
"�� �� Ѫ ��  982/  982 (100��)   �� �� �� �� 2570 / 2570 (+0)\n"+
"�� �� �� �� -802282              �� �� �� ��  276 /  276\n"+
"�� ʳ �� ��  350/  350           �� Ǳ �� ��  307\n"+
"�� �� ˮ ��  350/  350           �� �� �� ��  1691661\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"�� ħ  �� ����ң�ɵ��������ӡ��Ҿ�ֻ�ܵ������ǰ�...������(Saite)\n"+
"\n"+
" ����һλ��ʮ�����ĸ����Ը���ͨ���������࣬��î���������ճ�ʱ�Ŀ�����\n"+
" ����[25/ 40]  ����[20/ 37]  ����[15/ 35]  ��[20/ 40]  ����[11/ 31]\n"+
" ����[18/ 30]  ��Ե[20/ 20]  ��ʶ[30/ 30]  ����[21/ 21]  ��ò[18/ 18]\n"+
"\n"+
" ���ʦ���� ���ˡ�        �㻹�Ǹ������\n"+
" ��һǧ�Ű���ʮ�����ƽ��ʮ����������\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" ��ĿǰΪֹ���ܹ�ɱ�� 7449 ���ˣ������� 2 ����������ҡ�\n"+
" ��ĿǰΪֹ���ܹ�ɱ�� 3 ��ͬ�ţ������� 0 �������ʦ����\n"+
" ��ĿǰΪֹ���ܹ�ɱ�� 3 �����е��֣������� 0 ���������˾��\n"+
" ��ĿǰΪֹ���ܹ�ɱ�� 3564 ���޹����գ������� 28 ���Ƕ�ͯ��\n"+
" ��ĿǰΪֹ���ܹ����� 5 ���ˣ������� 3 ���Ƿ�����������\n"+
" ��ĿǰΪֹ���ܹ���ʦ�� 0 ���ˣ��������� 0 �Ρ�\n"+
"\n"+
" ��    ����  -802282     Ǳ    �ܣ� 307 ( 99%)   ʵս���飺  1691661\n"+
" ��    ����       60     ����������    25236     ����������       50\n"+
"\n", this_object());
	return 1;
}

int do_noodle()
{message_vision("$N˵����ѽ�����ҵ������ǣ�����һ�����������ˡ����������������
��\n",this_object());
	return 1;
}

int do_linqiyan()
{message_vision("$N˵��С���Ӱ�����������ѧУһ�����ѩ���ֵ��ˡ�������ʦ��Ӱ
��ɰ������ˣ��ϲ������ͷ\n",this_object());
	return 1;
}

int do_baoer()
{message_vision("$N˵����α���ѽ������������̶��Ψһ���������ˣ���ϧ������ʶʱ��
���Ѿ����������ˡ�����ʲôʱ������ټ�������....\n",this_object());
	return 1;
}

int do_yuki()
{message_vision("$N˵����˵�컳�ڰ����������ҵ���ǰ������һ�����������˲��ã�
����\n"+
"�����������֡����ǹ����ˣ��������˵㣬��У���������������ôһЩ������\n",this_object());
	return 1;
}

int do_ftlsk()
{message_vision("$N˵��������һ����û�¾͸������鷳������Ҳû�취��˭����\n"+
"����������ء�����Ϻ��ʱ��Ҫ���������ٷ�ˬˬ��heihei  \n",this_object());
	return 1;
}



