// Npc: /kungfu/class/nanshaolin/fangqiong.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;
string ask_for_join();

void create()
{
	set_name("����", ({ "fang qiong", "fang", "qiong"}));
	set("long", "����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("shaolin-cuff", 50);
	set_skill("luohan-cuff", 50);
	set_skill("hand", 50);
	set_skill("fengyun-hand", 50);
	set_skill("staff", 50);
	set_skill("pudu-staff", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("hand", "fengyun-hand");
	map_skill("staff", "pudu-staff");
	map_skill("parry", "pudu-staff");
	prepare_skill("cuff", "luohan-cuff");
	prepare_skill("hand", "fengyun-hand");

	set("inquiry",([
		"���" : (: ask_for_join :),
		"����" : (: ask_for_join :),
	]));
	create_family("��������", 21, "����");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(WEAPON_DIR+"staff/chanzhang")->wield();
}

void init()
{
	add_action("do_kneel", "kneel");
}

string ask_for_join()
{
	object me = this_player();

	if( (string)me->query("class")=="bonze" )
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��\n";
	if( (string)me->query("gender") != "����" )
		return "�����ӷ����գ����գ�Ůʩ����������Ľ�����֣���������Ժ�׼ҵ��ӡ�\n";
	me->set_temp("pending/join_bonze", 1);
	return "�����ӷ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}
int do_kneel()
{
	object me = this_player();
	string *prename = ({ "��", "��", "Ԫ", "��" });
	string name, new_name;
	int gen;

	if( !me->query_temp("pending/join_bonze") ) return 0;
	message_vision("$N˫�ֺ�ʮ�����������ع���������\n\n$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n", me, this_object() );
	name = me->query("name");
	if (me->query("family/family_name") == "��������")
		gen = me->query("family/generation");
	else gen = 22;
	new_name = prename[22-gen] + name[0..1];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");
	command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
	me->set("shen", 0);
	if (me->query("family/family_name") == "��������")
		me->set("title", "�������ɵ�"+chinese_number(gen)+"������");
	return 1;
}
#include "/kungfu/class/nanshaolin/fang.h";
