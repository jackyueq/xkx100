// Npc: /d/guiyun/npc/lugy.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;

// string ask_yao1();
string ask_yao2();

object ob = this_object();
void create()
{
	set_name("½��Ӣ", ({"lu guanying", "lu", "guanying"}) );
	set("long", "�������޳��ۣ�����������׳����\n");
	set("gender", "����" );
	set("nickname", "����ׯ��ׯ��" );
	set("age", 27);
	set("attitude", "peaceful");
//	set("apprentice",1);
	set("str",25);
	set("int",25);
	set("con",27);
	set("dex",26);
	set("max_qi", 1000);
	set("max_jing", 450);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 30);
	set("combat_exp", 70000);

	set_skill("force", 50);
	set_skill("bibo-shengong", 50);
	set_skill("dodge", 50);
	set_skill("anying-fuxiang", 40);
	set_skill("parry", 60);
	set_skill("strike", 40);
	set_skill("luoying-zhang", 35);
	set_skill("leg", 40);
	set_skill("xuanfeng-leg", 30);
	set_skill("sword", 60);
	set_skill("yuxiao-jian", 50);
	set_skill("taoism", 20);
	set_skill("literate", 60);
	set_skill("qimen-wuxing", 80);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "luoying-zhang");
	map_skill("leg", "xuanfeng-leg");
	map_skill("parry", "luoying-zhang");
	map_skill("sword", "yuxiao-jian");
	prepare_skill("strike", "luoying-zhang");

	set("rank_info/respect", "��ׯ��");
	set("shen_type", 1);
	set("shen", 200);
	create_family("�һ���", 3, "����");
	set("class", "fighter");
	set("yao", 10);   

	set("inquiry", ([
		"name": "����½��Ӣ�����������ׯ����",
		"rumors": "��˵�ɹű���Ҫ�����ˣ�����",
		"here": "�����ǹ���ׯ�������תת�ɣ������뵽�ͷ���Ϣ��",
		"��а": "����ʦ��ѽ�����������˼Ҷ�׼���Ҳ��ܸ�����ѧ�ա�",
		"��ҩʦ": "����ʦ��ѽ�����������˼Ҷ�׼���Ҳ��ܸ�����ѧ�ա�",
		"�һ���": "��˵��ʦ��ס�ĵط�����ϧû��ȥ������",
		"½�˷�": "���ҵĸ��ף��������˼���ʲô����",
		"½��Ӣ": "���ң��������¡�",
		"����ׯ": "�����ǻ����Ҹ���������Ѫ�Ž������ģ�����ׯԺ�����Σ�",
		"̫��": "����ׯǰ��Զ����һ���̲����Ĵ����",
		"ҩ" : "�������ұ�����ҩ���һ������ӿ��Ե���������ȡ��",
//		"���ž۾���": (: ask_yao1 :),
		"���ɼ�����": (: ask_yao2 :),
		"�Ż���¶��": 	"�Ż���¶�����������ޱȣ��������û��! ",
	]) );

	setup();

	carry_object("/clone/misc/cloth.c")->wear();
}

string ask_yao1()
{
	object ob = this_player();

	if (ob->query("family/family_name") != "�һ���")
		return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

	if (ob->query_condition("jingli_drug") > 0 )
		return RANK_D->query_respect(ob) + "�㲻�ǸճԹ�ҩ����ô����Ҫ�ˣ���ҩ����к����ˣ�����ʱ�������ɡ�";

	if (ob->query("max_jingli" ) < 200)
		return RANK_D->query_respect(ob) + "������������ҩ����к����ˣ�����ʱ�������ɡ�";

	if (present("sancai dan", ob))
		return RANK_D->query_respect(ob) + "���������ϲ����п�ҩ������ô����Ҫ�ˣ�����̰�����ᣡ";

	if (query("yao") < 1) return "�Բ���ҩ�Ѿ������ˣ��µĻ�δ������";
   
	new("/d/taohua/obj/sancai-dan")->move(ob);

	add("yao", -1);

	message_vision("$N���һ�����ž۾�����\n", ob);
	return "�ðɣ���ҩ��֮���ף�������֮�˴��кô�����ҪС���ղغ��ˡ�";
}

string ask_yao2()
{
	object ob = this_player();

	if (ob->query("family/family_name") != "�һ���")
		return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

	if (ob->query_condition("medicine") > 0 )
		return RANK_D->query_respect(ob) + "�㲻�ǸճԹ�ҩ����ô����Ҫ�ˣ���ҩ����к����ˣ�����ʱ�������ɡ�";

	if (this_player()->query("max_neili") < 400)
		return RANK_D->query_respect(ob) + "������������ҩ����к����ˣ�����ʱ�������ɡ�";

	if (present("liuren wan", ob))
		return RANK_D->query_respect(ob) + "���������ϲ����п�ҩ������ô����Ҫ�ˣ�����̰�����ᣡ";

	if (query("yao") < 1) return "�Բ���ҩ�Ѿ������ˣ��µĻ�δ������";

         if(ob->query("max_neili")>= (ob->query_skill("force")*8+ob->query("combat_exp",1)/1000))
                     return RANK_D->query_respect(ob) + "��ҩ�Ѿ������ڰ��������������Ϊ�ˣ�";
	new("/clone/medicine/liuren-wan")->move(ob);

	add("yao", -1);

	message_vision("$N���һ�����ɼ����衣\n", ob);
	return "�ðɣ���ҩ��֮���ף�������֮�˴��кô�����ҪС���ղغ��ˡ�";
}


