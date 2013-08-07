// Npc: /d/guiyun/npc/lucf.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;

int ask_ci();
int ask_yue();

void create()
{
	set_name("½�˷�", ({"lu chengfeng", "lu", "chengfeng"}) );
	set("nickname", "����ׯ��");
	set("long",
		"����ɫ���ݣ�������ߣ��������һ���������ƺ�˫���вм���\n");
	set("gender", "����" );
	set("age", 42);
	set("attitude", "friendly");
	set("apprentice",1);
	set("str",30);
	set("int",29);
	set("con",28);
	set("dex",5);
	set("max_qi", 1600);
	set("max_jing", 1000);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 40);
	set("combat_exp", 800000);


	set_skill("force", 100);
	set_skill("bibo-shengong", 90);
	set_skill("dodge", 30);
	set_skill("anying-fuxiang", 85);
	set_skill("parry", 90);
	set_skill("strike", 100);
	set_skill("luoying-zhang", 90);
	set_skill("leg", 110);
	set_skill("xuanfeng-leg", 100);
	set_skill("sword", 90);
	set_skill("yuxiao-jian", 80);
	set_skill("taoism", 90);
	set_skill("literate", 100);
	set_skill("qimen-wuxing", 140);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "luoying-zhang");
	map_skill("leg", "xuanfeng-leg");
	map_skill("parry", "yuxiao-jian");
	map_skill("sword", "yuxiao-jian");
	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");

	set("rank_info/respect", "ׯ��");
	set("shen_type", 1);
	set("shen", 100);
	set("vendetta_mark", "�һ���");
	create_family("�һ���", 2, "����");
	set("class", "fighter");

	set("inquiry", ([
		"name": "�Ϸ�½�˷磬�������ׯ����",
		"rumors": "�ܾ�û����ʦ�ֵ���Ϣ�ˣ���֪���Ƿ�������⣿",
		"here": "�����ǹ���ׯ�������תת�ɣ������뵽�ͷ���Ϣ��",
		"��" : "������ϵĴ���һλ��Ӣ�ۡ������������",
		"��" : (: ask_ci :),
		"ҩ" : "��ҩ�ҽ���С����Ӣ�����ˡ�",
		"���ž۾���": "��ҩ�ҽ���С����Ӣ�����ˡ�",
		"���ɼ�����": "��ҩ�ҽ���С����Ӣ�����ˡ�",
		"�Ż���¶��": "��ҩ�ҽ���С����Ӣ�����ˡ�",
		"��" : "�����������д�ģ��㿴��ô����",
		"��Ӣ��": "���ȿ�������˵���ѵ���û�ж������״���",
		"�����": "���ȿ�������˵���ѵ���û�ж������״���",
		"����"  : (: ask_yue :),
		"������" : (: ask_yue :),
		"��а": "���Ƕ�ʦѽ����Ȼ��������ǵ�˫�ȣ��������ǳ�������һ��Ϊʦ������Ϊ��ѽ��",
		"��ҩʦ": "���Ƕ�ʦѽ����Ȼ��������ǵ�˫�ȣ��������ǳ�������һ��Ϊʦ������Ϊ��ѽ��",
		"��ʦ" : "�����һ�������ҩʦ�ˣ��������������Ĳ���ѧ���黭���壬������ԣ�ҽ�����࣬�������У���һ������",
		"��ʦ" : "�����һ�������ҩʦ�ˣ��������������Ĳ���ѧ���黭���壬������ԣ�ҽ�����࣬�������У���һ������",
		"����": "�ţ�����Сʦ�ã��Ǽ�ʦ���������顣",
		"�һ���": "�û���ԭ������������ʱ��ѽ����ʦ�����뵺ʱ�����˺�ͼ�ء�",
		"½�˷�": "�����Ϸ��ң���ʲô����",
		"½��Ӣ": "����СȮ����ǰ�����ɶ�������ϰ�գ�����ʦ����׼��������ѧ���ˡ�",
		"��Ӣ": "����СȮ����ǰ�����ɶ�������ϰ�գ�����ʦ����׼��������ѧ���ˡ�",
		"����ׯ": "�����ǻ�����������Ѫ�Ž������ģ�����ׯԺ�����Σ�",
		"̫��": "����ׯǰ��Զ����һ���̲����Ĵ����",
		"�Ź�": "�Ź�֮�壬������ꡣ����Ϊ�磬����Ϊ�㣻�������ߣ�������һ������м䡣",
		"����": "Ǭ�����������Σ������飬�������������ۣ��޸��룻����ȱ�����¶ϡ�",
		"����": "����ˮ��ˮ��ľ��ľ���𣬻������������𡣽��ľ��ľ����������ˮ��ˮ�˻𣬻�˽�",
		"�׾�": "��һ�����������ʮ���Ե����飬һ�����ѵÿ�����",
		"����": "��һ�����������ʮ���Ե����飬һ�����ѵÿ�����",
		"�����澭": "���������Ȿ�����������Ǵ�ң�",
	]) );

	set("chat_chance", 5);
	set("chat_msg",({
		"½�˷�����Ƿ�����̾һ����ĬȻ��������������¡�\n",
	}));
	setup();

	carry_object(WEAPON_DIR+"sword/yudi")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object letter;
	string letter_desc;

	if (!ob->query("thd/receive"))
	{
		command("say û�м�ʦ����ɣ�½ĳ�������Խ���ʦ���书ת�����ˣ�");
		if (!ob->query("family") && ob->query_int() >= 28)
		{
			command("say �����ҿ�" + RANK_D->query_respect(ob) + "�����ʻ����������ɣ���дһ���Ƽ��ţ�����ȥ�Ҽ�ʦ�ɡ�");
			letter = new("/d/guiyun/obj/tuijian_xin");
			letter->set("owner", ob->query("id"));
			letter_desc = "����½�˷�д����ҩʦ��һ���ţ�����д�ţ�\n��ʦ���ϣ�����" + ob->query("name") + "һ���������뱾�ɣ����Ӳ�����ר�����������ʲ����ش��Ƽ����ʦ���ᡣ  �˷�ߵ��\n";
			letter->set("long", letter_desc);
			letter->move(ob);
			message_vision("½�˷��ͳ�һ���Ƽ��ţ�д��$N�����֣�������$N��\n", ob);
			command("say ��ʦ���һ�������ҩʦ������Ҫ���ٰ����������ϵ��������һ�����λ�������...��...�������뿴...");
			command("consider");
			command("doubt chengfeng");
			command("sigh");
			command("say ��Ȼ�벻�����ˣ���ȥ����ʦ�������ɣ������ٰ����ϵ�ţ�Ҵ忪��һ��С�ꡣ");
		}
		return;
	}
	ob->delete("thd/receive");
	if (ob->query("gender") != "����" && ob->query("gender") != "Ů��") {
		command("say �㲻�в�Ů����ʲô�����������");
		return;
	}
	if (ob->query("shen") <= -100000) {
		command("say ��ʦ��ƽ�����������ˣ����������޶�����аħ���������һ����ȥ���ʦ�ɣ�");
		return;
	}
	if (ob->query("shen") >= 100000) {
		command("say ��ʦ��ƽ�����������ˣ������������������Ĺ�������֮ͽ������һ����ȥ���ʦ�ɣ�");
		return;
	}
	if (ob->query_int() < 28) {
		command("say ��Ĳ�������������ȥ���ʦ�ɣ�");
		return;
	}
	if (ob->query("class") == "bonze") {
		command("say ��ʦ�Ƚ��������ֺ��У��ҿɲ����������㡣��ȥ���ʦ�ɣ�");
		return;
	}
	command("say ��Ȼ��ʦ����Ҿ�����Ϊͽ�ɡ�");
	command("recruit " + ob->query("id"));
	ob->set("class", "fighter");
}

void init()
{
	object ob = this_player();

	add_action("do_answer","answer");
	add_action("do_answer","huida");
	add_action("do_kill","kill");
	::init();
	if (ob->query("family/family_name") == "�һ���") {
		if ((int)ob->query("shen") <= -100000) {
			message_vision("½�˷��$N�ȵ����������ˣ������ʦ���������������ң���\n", ob);
			message_vision("½�˷��$N�ȵ����ӽ���������Ҳ�����һ����ĵ����ˣ�\n", ob);
			ob->delete("family");
			ob->set("title", "�һ�����ͽ");
		}
		else if ((int)ob->query("shen") >= 100000) {
			message_vision("½�˷��$N�ȵ������Ǵ����������˵������ʦ��޹���������α���ӡ�\n", ob);
			message_vision("½�˷��$N�ȵ����ӽ���������Ҳ�����һ����ĵ����ˣ�\n", ob);
			ob->delete("family");
			ob->set("title", "�һ�����ͽ");
		}
	}
}

int do_kill(string arg)
{
	object ob;
	object me = this_player();
	int perform, payed;

	if (!arg) return 0;
	ob = present(arg, environment(me));
	if (ob == this_object() || ob == me) return 0;
	if (!ob || !ob->is_character()) return 0;
	if (ob->query("family/family_name") == "�һ���") {
		if (me->query("family/family_name") == "�һ���") {
			message_vision("½�˷���$N�ȵ���Сū�ţ�Ҫ�췴�����Լ���ͬ�Ŷ�ɱ����\n", me);
		}
		else {
			message_vision("½�˷���$N�ȵ����󵨿�ͽ������������ׯ��Ұ����\n", me);
			message_vision("½�˷��$N˵���������ÿ�����������ʰ���" + RANK_D->query_rude(me) + "��\n", ob);
			kill_ob(me);
		}
		me->set("vendetta/�һ���", 1);
		return 1;
	}
	return 0;
}

int ask_ci()
{
	object ob = this_player();

	command("say д���״ʵĴ�Ӣ�ۡ�����ܾ��������¡�\n");
	if(!ob->query_temp("guiyun_lutemp"))
		ob->set_temp("guiyun_lutemp", 1);
	return 1;
}

int ask_yue()
{
	object ob = this_player();

	if(ob->query_temp("guiyun_lutemp") >= 1) {
		command("say ��ϧ�ҵ�������һ����������ԭ�ⲻ̫�������֪" + RANK_D->query_respect(ob) + "�ܷ񿴳�����\n");
		ob->set_temp("guiyun_lutemp", 2);
	}
	else {
		command("say ���������ҷǳ����ص�һλ��Ӣ�ۡ�\n");
	}
	return 1;
}

int do_answer(string arg)
{
	object ob = this_player();

	if (ob->query_temp("guiyun_lutemp") == 2) {
		tell_room(environment(ob), ob->name() + "����½�˷�٩٩��̸��\n", ({ob}));
		if (arg == "֪����,�Ҷ���˭��?" || arg == "֪���٣��Ҷ���˭����" 
		|| arg == "֪����,�Ҷ���˭��" || arg == "֪���٣��Ҷ���˭��") {
			if (!present("tuifa tujie", ob) && query_temp("tuifa_give") < 5) {
				say("½�˷糤��һ�������ⷬ���飬���ղű��㿴�ƣ���νƽ��һ֪�ѣ��Ȿ�ȷ����͸���ɡ�\n");
				new("/d//guiyun/obj/tuifa")->move(ob);
				ob->delete_temp("guiyun_lutemp");
				add_temp("tuifa_give",1);
			}
			else {
				say("½�˷糤��һ�������ⷬ���飬���ղű��㿴�ƣ���νƽ��һ֪�ѣ�ֻ��ϧ�Ϸ���û��ʲô���������ġ�\n");
			}
		}
		else {
			command("? " + ob->query("id"));
			message_vision("½�˷��ɻ�ؿ���$N��" + RANK_D->query_respect(ob) + "�ƺ�Ӧ�ö�ѧЩ�鷨�滭�ɣ�\n", ob);
		}
		return 1;
	}
//		say("½�˷�˵����һ����͸ֽ�����������͸�ҵ��ľ���\n");
	return 0;
}
