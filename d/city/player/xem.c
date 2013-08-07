// xem.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("��÷", ({ "xem"}));
	set("gender", "Ů��");
        set("long","��̶��һ���������������书֮��տ���������ܼ���
Ϊ��ǫ�ͳ嵭�����������󾫡��������ɴ˵��Է����
���ڽ������ն��ʱ���ͦ��������Ǵ��ߵ���Ц
��һ�ƴ��磬��������������ɱ�ĺ��⡣������һ����
�����������ڽ�������б����Ǵ��С�\n");
	set("title", HIW"ʥ��"HIG"���̵����Ž���"NOR"�����ɵ��Ĵ�����");
	set("age", 40);
	set("class", "bonze");
	set("attitude", "friendly");

	set("kar", 28);
	set("per", 27);
	set("int", 30);
	set("dex", 16);
	set("con", 15);
	set("str", 19);
	set("weiwang", 70);
	set("shen", 0);
	set("combat_exp", 49927955);
	set("PKS", 6);
	set("MKS", 1587);

	set("max_jing", 804);
	set("jing", 804);
	set("max_qi", 2732);
	set("qi", 2732);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 8610);
	set("neili", 8610);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("blade", 561);
	set_skill("buddhism", 200);
	set_skill("claw", 254);
	set_skill("cuff", 254);
	set_skill("dagou-bang", 784);
	set_skill("dodge", 561);
	set_skill("feixing-shu", 787);
	set_skill("finger", 561);
	set_skill("force", 561);
	set_skill("hanbing-mianzhang", 792);
	set_skill("huifeng-jian", 794);
	set_skill("jinding-zhang", 794);
	set_skill("jiuyin-baiguzhao", 702);
	set_skill("kongming-quan", 792);
	set_skill("linji-zhuang", 586);
	set_skill("literate", 300);
	set_skill("mahayana", 204);
	set_skill("parry", 561);
	set_skill("qishang-quan", 792);
	set_skill("qiufeng-chenfa", 776);
	set_skill("shenxing-baibian", 300);
	set_skill("staff", 250);
	set_skill("strike", 257);
	set_skill("sword", 561);
	set_skill("throwing", 250);
	set_skill("tiangang-zhi", 787);
	set_skill("unarmed", 560);
	set_skill("whip", 250);
	set_skill("yanxing-dao", 794);
	set_skill("zhutian-bu", 781);

	map_skill("unarmed", "kongming-quan");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("force", "linji-zhuang");
	map_skill("cuff", "qishang-quan");
	map_skill("parry", "jingding-zhang");
	map_skill("whip", "qiufeng-chenfa");
	map_skill("throwing", "feixing-shu");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("staff","dagou-bang");
	map_skill("strike", "jinding-zhang");
	map_skill("finger", "tiangang-zhi");
	map_skill("dodge", "zhutian-bu");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
	]));

	create_family("������",4, "����");
	setup();
	carry_object(__DIR__"xem_sword")->wield();
	carry_object(CLOTH_DIR"ni-cloth")->wear();
        carry_object(CLOTH_DIR"ni-shoe")->wear();
}

int do_skills()
{
message_vision("$N˵�� �����еĻ����书���£�\n"+
"�ԩ�������������������������������������������������������������\n"+
"  �������� (blade)                         - ��ɲ� 561/    0\n"+
"  �����ķ� (buddhism)                      - ��ɲ� 200/    0\n"+
"  ����צ�� (claw)                          - ��ɲ� 254/    0\n"+
"  ����ȭ�� (cuff)                          - ��ɲ� 254/    0\n"+
"���򹷰��� (dagou-bang)                    - ��ɲ� 784/    0\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 561/    0\n"+
"�������� (feixing-shu)                     - ��ɲ� 787/    0\n"+
"  ����ָ�� (finger)                        - ��ɲ� 561/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 561/    0\n"+
"  �������� (hanbing-mianzhang)             - ��ɲ� 792/    0\n"+
"���ط������ (huifeng-jian)                - ��ɲ� 794/    0\n"+
"�������� (jinding-zhang)                 - ��ɲ� 794/    0\n"+
"�������׹�ץ (jiuyin-baiguzhao)            - ��ɲ� 702/    0\n"+
"������ȭ (kongming-quan)                   - ��ɲ� 792/    0\n"+
"���ټ�ʮ��ׯ (linji-zhuang)                - ��ɲ� 586/    0\n"+
"  ����д�� (literate)                      - ��ɲ� 300/    0\n"+
"  ������͹� (mahayana)                    - ��ɲ� 204/    0\n"+
"  �����м� (parry)                         - ��ɲ� 561/    0\n"+
"������ȭ (qishang-quan)                    - ��ɲ� 792/    0\n"+
"�������� (qiufeng-chenfa)                - ��ɲ� 776/    0\n"+
"  ���аٱ� (shenxing-baibian)              - ��ɲ� 300/    0\n"+
"  �����ȷ� (staff)                         - ��ɲ� 250/    0\n"+
"  �����Ʒ� (strike)                        - ��ɲ� 257/    0\n"+
"  �������� (sword)                         - ��ɲ� 561/    0\n"+
"  �������� (throwing)                      - ��ɲ� 250/    0\n"+
"�����ָѨ�� (tiangang-zhi)                - ��ɲ� 787/    0\n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 560/    0\n"+
"  �����޷� (whip)                          - ��ɲ� 250/    0\n"+
"�����е� (yanxing-dao)                     - ��ɲ� 794/    0\n"+
"�����컯�� (zhutian-bu)                  - ��ɲ� 781/    0\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  804/  804 (100%)    �� �� �� ��    0 /    0 (+0)\n"+
"�� �� Ѫ �� 2732/ 2732 (100%)    �� �� �� �� 8610 / 8610 (+0)\n"+
"�� ʳ �� ��    0/  290           �� Ǳ �� ��  0\n"+
"�� �� ˮ ��    0/  290           �� �� �� ��  49927955\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"�� ��  �� ������˶ʿ���̵����Ž��ڶ����ɵ��Ĵ����� ��÷(Xem)\n"+
"\n"+
" ����һλ��ʮ���Ů�����࣬������һ��һ�ճ�ʱ��������\n"+
" ������[ 55]  ���ԣ�[ 60]  ���ǣ�[ 61]  ����[ 52]\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ս�������� 11571809            ս�������� -21221796\n"+
" ս���˺���       30            ս��������         1\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ�ɱ�� 1593 ���ˣ������� 6 ����������ҡ�\n"+
"\n"+
" �㵽ĿǰΪֹ�ܹ����� 0 ���ˣ������� 0 ���Ƿ�����������\n"+
"\n"+
" ��    ����        0     Ǳ    �ܣ�   0 (100%)   ʵս���飺 49927955\n"+
" ��    ����       60     ����������        0     ����������       70\n"+
"\n", this_object());
	return 1;
}

