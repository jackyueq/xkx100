// ding.c ������
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

#define YINLINFEN "/clone/medicine/poison/yinlinfen"
#define HONGLINFEN "/clone/medicine/poison/honglinfen"
#define DUCHONGFEN "/clone/medicine/poison/duchongfen"
#define BINGPOFEN "/clone/medicine/poison/bingpofen"

string ask_me();
string ask_du1();
string ask_du2();
string ask_ding();
string ask_azi();
string ask_job();
string ask_huoyan();
string ask_yinlinfen();
string ask_bingpofen();
string ask_duchongfen();
string ask_honglinfen();
 
void create()
{
	set_name("������", ({ "ding chunqiu", "ding" }));
	set("nickname", "�����Ϲ�");
	set("long", 
		"����ɫ������ͷ�׷�������������ף�ͯ�պ׷����������ͼ\n"
		"���е���������һ�㡣\n"
		"�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
		"��������������ò���棬�ɷ���ǡ�\n");
	set("gender", "����");
	set("age", 60);
	set("per", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("shen", -150000);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 400000);

	set_skill("force", 200);
	set_skill("huagong-dafa", 200);
	set_skill("throwing", 200);
	set_skill("feixing-shu", 300);
	set_skill("dodge", 200);
	set_skill("zhaixinggong", 300);
	set_skill("strike", 200);
	set_skill("chousui-zhang", 300);
	set_skill("claw", 200);
	set_skill("sanyin-wugongzhao", 300);
	set_skill("parry", 200);
	set_skill("staff", 200);
	set_skill("poison", 150);
	set_skill("tianshan-zhang", 300);
	set_skill("literate", 100);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("book_count", 1);
	set("zhen_count", 1);
	set("san_count", 1);
	set("huoyan_count", 1);
	set("ding_count", 0);
	set("di_count", 10);
	set("no_get",1);
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		(: perform_action, "strike.huoqiu" :),
		(: perform_action, "strike.huoqiang" :),
		(: perform_action, "strike.yinhuo" :),
		(: perform_action, "strike.biyan" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry", ([
		"����" : (: ask_azi :),
		"��ľ����" : (: ask_ding :),
		"����" : (: ask_me :),
		"���޶���" : (: ask_me :),
		"������" : (: ask_du1 :),
		"��Ц��ңɢ" : (: ask_du2 :),
		"��ң��Цɢ" : (: ask_du2 :),
//		"����" : (: ask_huoyan :),
		"����"  : (: ask_job :),
		"job"  : (: ask_job :),
		"ľ��" : "ץ���������õġ����͵���ͷ����㡣",
		"������" : "���������������ɿ�ɽ��ʦ, �����Ͽ��ͷ��", 
		"���޺�" : "��Ϲ������, ������ǡ�",
		"����" : "�����Բ�����ﶼ�����ɵ���������",
		"������" : "û��ûС�ġ��ٽ��ҷ����㡣",
		"����" : "���������ɱ������������ʥ����ô������",
		"��������" : "�Ժ�����ɡ�",
		"����" : "���������ᡣ",
		"���׷�"	: (:ask_yinlinfen:),
		"yinlin fen" : (:ask_yinlinfen:),
		"���׷�" : (:ask_honglinfen:),
		"honglin fen" : (:ask_honglinfen:),
		"���Ƿ�" : (:ask_bingpofen:),
		"bingpo fen" : (:ask_bingpofen:),
		"�����": (:ask_duchongfen:),
		"duchong fen": (:ask_duchongfen:),
	]));
	create_family("������", 1, "��ɽ��ʦ");
	set("class", "taoist");
	setup();
//	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/dao-cloth")->wear();
}

void init()
{
	object me, ob;
	::init();
	ob = this_player();
	me = this_object();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}       
	add_action("do_flatter", "flatter");
	add_action("do_xian", "xian");
        add_action("do_qiecuo","qiecuo");
}

void greeting(object me)
{
	mapping myfam;
	int shen;
	
	if (!objectp(me) || environment(me)!=environment()) return;
	myfam = (mapping)me->query("family");
	shen = me->query("shen");

	if(!myfam) command("say ��ǧ����������ɽ, Ī����������������ɣ�");
	else if(myfam["family_name"] != "������" && !me->query_temp("xx_job"))
		command("say ��ǧ������������ɽ������Ľ�������ҵ��ʵ°ɣ�");
	else if(myfam["family_name"] != "������" && me->query_temp("xx_job"))
	command("nod " + me->query("id"));
	else if(shen > -1000 && shen < 0) command("say ����ô��ģ�������һ��İ׵���Ϣ��");
	else if(shen > 0 && shen < 100000) command("say ���ۣ���ҺͰ׵����˽��ͣ���������ǲ��ǣ�");
	else if(shen > 100000)
	{
		command("say �㾹�ҺͰ׵����˽��ͣ������������ȥ�ɣ�");
		command("expell " + me->query("id"));
	}
	else command("say ��ͽ��������������ô���ˣ�");
	if((myfam["family_name"] == "������")&&(!me->query_skill("huagong-dafa",1))&&(me->query("combat_exp")>500000))
        {
                command("say �㾹�ҷ��������ķ��������������ȥ�ɣ�");
                command("expell " + me->query("id"));
        }
}

void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > -100) {
		command("say ����Խ����Խ��׵������Ե׵ġ�");
		return;
	}
	if ((int)me->query("combat_exp") < 10000) {
		command("say �����΢ĩ���������ѧ�����ɵ������");
		return;
	}
	if( me->query_temp("pending/flatter") ) {
		command("say ����˲������ɷ�����������������㣿");
		return;
	} else {
		command("say ���������ɱ������������ʥ����ô������");
		message_vision("�����Ϲ�΢��˫�ۣ������룬һ����$N����(flatter)�����ӡ�\n", me);
		me->set_temp("pending/flatter", 1);
	}
}

int do_flatter(string arg)
{
	object me=this_player(), ob=this_object();

/* ����ҲҪ��������ƨ��
	if( !me->query_temp("pending/flatter") )
		return 0;
*/
	if( !arg ) return notify_fail("��˵����ʲô��\n");
//	ob->set_temp("pending/flatter", 0);
	switch(random(5))
	{
		case 0: message_vision("$N��$n�����޵��������˼�һ����������ѣ�һҡ�������޹⣡\n", me,ob); break;
		case 1: message_vision("$N��$n�����޵����������ɴ���ڶ����������ԣ����������ţ������һ������������֮�أ�\n", me,ob); break;
		case 2: message_vision("$N��$n�����޵�����������������һϯ��������Ī����ֻ����������֣�С�˸��������������ǣ�\n", me,ob); break;
		case 3: message_vision("$N��$n�����޵�������������֮�������������֮�����̹��Ͽ���ٵ����������޵ڶ����������ɵ����£�\n", me,ob); break;
		case 4: message_vision("$N��$n�����޵��������񹦸��������µ�һ��ս�޲�ʤ�����޲��ˣ�\n", me,ob); break;
	}
	message_vision("$N����˵����" + arg + "\n", me);
	if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0 ||
		strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 ))
	{
		if(me->query_temp("pending/flatter"))
		{
			me->set_temp("pending/flatter", 0);
			me->set_temp("ding_flatter", 1);
			command("smile");
			command("say �⻹��ࡣ\n");
			command("recruit " + me->query("id"));
			CHANNEL_D->do_channel(me, "chat",  "�������ɣ�������أ��������Ž��ޱȣ�");
		}
		else
		{
			command("say �����������ô���������ǰ;������������\n");
			me->set_temp("ding_flatter", 1);
			return 1;
		}
	} else
	{
		command("say ����˲������ɷ�����������������㣿");
	}
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}

// �������ɣ�������أ��������Ž��ޱ�

string ask_me()
{
	mapping fam; 
	object ob;
	
	if(!(fam = this_player()->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if(query("book_count") < 1) return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/dujing_2");
	ob->move(this_player());
	return "�ðɣ��Ȿ�����޶��������û�ȥ�ú����С�";
}
string ask_du1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_skill("poison",1)<50)
		return "��Ķ������δ�����ò������ֶ�����";
	if (query("zhen_count") < 1) return "�������ˣ������붼�����ˡ�";
	add("zhen_count", -1);
	ob = new("/d/xingxiu/obj/bilinzhen");
	ob->move(this_player());
	return "�ðɣ������������Щ��ɡ�";
}
string ask_du2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_skill("poison",1)<100)
		return "��Ķ������δ�����ò������ֶ�����";
	if (query("san_count") < 1) return "�������ˣ�����ûʲôʣ���ˡ�";
	add("san_count", -1);
	ob = new("/clone/medicine/poison/sanxiaosan");
	ob->move(this_player());
	return "�ðɣ������ҩ���û�ȥ�Ƽ����ðɡ�";
}
string ask_huoyan()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_skill("poison",1)<100)
		return "��Ķ������δ�����ò������ֶ�����";
	if (query("huoyan_count") < -100) return "�������ˣ�����ûʲôʣ���ˡ�";
	add("huoyan_count", -1);
	ob = new("/d/xingxiu/npc/obj/huoyan.c");
	ob->move(this_player());
	return "�ðɣ��Ҿ͸���ѻ���ɡ�";
}

string ask_ding()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	switch (query("ding_count") )
	{
		case 0:
			command("kick1 "+this_player()->query("id"));
			add("ding_count", 1);
			return "��������Щ��������Ĺ���ͽ����ʲô�ã�����СС����ľ��������͵�ߣ�";
		case 1:
			command("sigh "+this_player()->query("id"));
			add("ding_count", 1);
			return "С���ϰ���ľ���������ˣ�˭����ץ������˭���Ǳ��Ŵ���ӣ�";
		default: 
			command("grin");
			return "�������������أ��㻹��ôû��ɫ�Ͻ��˰̡�����ǲ��ǣ�";
	}
	return "�ߡ�";
}

string ask_azi()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if(query("ding_count") == 2 || this_player()->query_temp("smwd/step"))
	{
		this_player()->set_temp("smwd/step", 1);
		command("kick "+this_player()->query("id"));
		add("ding_count", 1);
		return "��������������ˣ��������ģ�������ȥ׷��";
	}
	else return "�����Ǹ����ɰ���С��ƨ�����Ϸ���ϲ����";
}

string ask_job()
{
	object ob,me = this_player();
 
	if(!me->query("family") || me->query("family/family_name") != "������")
		return "���������̬�ȹ������β��������������أ�";
	if(me->query("combat_exp") < 100000) 
		return "�����������ټӰ����������ܿ�Ϳ���Ϊ�����ҷ����ˡ�";
	if(me->query("shen") >= 0 ||
		me->query("shen") > -(me->query("combat_exp")/10)) 
		return "ͽ������������ĳ��������ڰ�����Щ���㲻��Ҳ�ա�";
	if(interactive(me) && me->query_temp("job_busy")) 
		return "��˵Ҫ�����ɷ��ǣ���ô�������﷢����";
	if(interactive(me) && me->query_condition("wait_xx_task")) 
		return "�����������黹�ã���������Ϊ�ҷ��ǡ�";
	if(query("di_count") < 1) 
		return "�����������黹�ã��������Ҿͱ���������鲻���ˡ�";

	ob = new(__DIR__"obj/di");
	add("di_count", -1);
	ob->move(me);
	ob->set("name", BLU"����̵�"NOR);
	ob->set("long", BLU"����Ѷ̵ó��棬ֻ�����ߴ�������ͨ���������Ө�ɰ���\n" NOR);
	ob->set("xx_user", getuid(me));
	me->set_temp("xx_job", 1);
	message_vision("$N�ó�һֻ���ƶ̵ѣ�����$n��\n", this_object(), me);
	return "������������鲻�ѣ�ͽ����Ҫ���Ϊ�ҷ��ǲ��ǣ�\n";    
}

int do_xian(string arg)
{
	object who, me, ob;
	mapping quest;
	who = this_player();
	me = this_object();

	if(who->is_busy() || who->is_fighting()) 
		return notify_fail("����æ���ء�\n");
	if(!arg) return notify_fail("��Ҫ�׸�����ʲô������\n");
	if(!objectp(ob = present(arg, who)))
		return notify_fail("������û������������\n");
	if(!who->query_temp("xx_job"))
		return notify_fail("���������ڵ����黹û����������׶�����\n"); 
	message_vision(HIY "\n$n�Ϲ��Ͼ��ؽ�"+ob->query("name")+HIY"�ó���˫�����ϣ���Ҫ�׸�$N��\n\n"NOR, me, who);
	if(me->is_busy())
	{
		"/cmds/std/say"->main(this_object(),"����æ���أ���ȵȡ�");
		return notify_fail("��������ȵȡ�\n");
        }
	if(!mapp(quest = who->query_temp("quest")) )
	{
		"/cmds/std/say"->main(this_object(),"���ø�"+ob->name()+CYN"���Ҹ��"NOR);
		return notify_fail("���ɶ��ⶫ��������Ȥ��\n");
	}
	if( quest["time"] < time())
	{
		"/cmds/std/say"->main(this_object(),"�ţ���ô�òŰ��꣬���ʲôȥ�ˣ����ҹ�һ��ȥ��");
		who->apply_condition("wait_xx_task", 40);
		return notify_fail("���ˣ����������ˡ�\n");
	}
	if(userp(ob))
	{
		command("stare " + who->query("id"));
		"/cmds/std/say"->main(this_object(),"�����üٻ�����ƭ�����ɣ����ҹ���ȥ��");
		message_vision("\n˵��$N����һ�ӣ�һ���ھ��������ͽ�$nɨ�����⣡\n\n", me, who);
		who->move("/d/xingxiu/riyuedong1");
		message("vision","ֻ����������һ����������"+who->query("name")+"�����¶���ֱ���˳�����ˤ�˸��Ľų��죡\n", environment(who), who);
		who->receive_wound("jing", 200);
		who->receive_wound("qi", 250);
		who->apply_condition("wait_xx_task", 30);
		who->delete_temp("quest");
		who->set_temp("last_id", quest["last_id"]);  
		who->start_busy(5);
		return notify_fail("��⣬�����ˣ�\n");
	}
	if(ob->query("id") != quest["id"])
	{
		command("hmm " + who->query("id"));
		"/cmds/std/say"->main(this_object(),"���ø�"+ob->query("name")+CYN"����������ʲô�ã�");
		return notify_fail("���������״����ˡ�\n");
	}
	ob->move(me);
	me->start_busy(2);
	call_out("destroying", 0, ob, me);
	call_out("done", 3, who);       
	return 1;
}

void done(object me)
{
	int hgdf, poison;
	mapping fam;
  
	if(!me) return;
	hgdf = me->query_skill("huagong-dafa",1);
	poison = me->query_skill("poison",1);
	fam = (mapping)me->query("family");

	command("pat " + me->query("id"));       
	command("say ��������Ȼ���ҵ�����������Ҫ�Ķ������Ҿ�ָ��ָ����ɡ�");
	if(fam["family_name"] == "������")
	{
		if(hgdf < 180 && SKILL_D("huagong-dafa")->valid_learn(me))
			me->improve_skill("huagong-dafa", me->query("xx_points")*5);   
		if(poison < 150 && SKILL_D("poison")->valid_learn(me))
			me->improve_skill("poison", me->query("xx_points")*5);
		me->add("xx_points", 1);          
		tell_object(me, "��Ŀǰ�Ѿ�Ϊ���ɷֵ���"+chinese_number(me->query("xx_points"))+"���ǳ\n");
		me->add("family/fealty",me->query("xx_points"));
		tell_object(me, "��������ҳ϶������ˡ�\n");
	}
	call_out("ok", 0, me);                    
}

void destroying(object obj, object me)
{
	message_vision("$N����$n��ϸ�ض�����һ���������ص��˵�ͷ������¶����Ц�ݡ�\n", me, obj);
	destruct(obj);
}

void ok(object me)
{
	mapping quest;
	if(!me) return;
   
	quest = me->query_temp("quest");
	tell_object(me, "���������ɵ�ָ�㣬��������˲��٣�\n"); 
	tell_object(me, GRN"���ó�"+chinese_number(quest["pot_reward"])+"��Ǳ�ܺ�"+chinese_number(quest["exp_reward"])+"�㾭��Ľ�����\n"NOR);
	me->add("combat_exp", quest["exp_reward"]);
	me->add("potential", quest["pot_reward"]);
	me->add("shen", -(quest["exp_reward"]*15));
	me->delete_temp("quest");
	me->set_temp("last_id", quest["last_id"]);     
//	me->apply_condition("job_busy", 3);  
	me->clear_condition("job_busy");
	return;
}

string ask_yinlinfen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (me->query_skill("poison",1)<100)
		return "��Ķ������δ�����ò������ֶ�����";
	ob=new(YINLINFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"��������������";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "�������ˣ�"+ob->query("name")+"���ڲ��������С�";
      if (owner->query("family/family_name") == "������")
           return ob->query("name")+"�����ڱ���" + owner->query("name") +"���У���Ҫ�þ�ȥ�����ɡ�";
      else
           return "����Ϊ���µ����أ�"+ob->query("name")+"����������" + owner->query("name") +"֮�֣����ȥ����ɱ�ˣ��Ѷ���ȡ������";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "��"+ob->query("name")+"�����ȥ��ϣ�����ܺú����á�";
}

string ask_duchongfen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (me->query_skill("poison",1)<100)
		return "��Ķ������δ�����ò������ֶ�����";
	ob=new(DUCHONGFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"��������������";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "�������ˣ�"+ob->query("name")+"���ڲ��������С�";
      if (owner->query("family/family_name") == "������")
           return ob->query("name")+"�����ڱ���" + owner->query("name") +"���У���Ҫ�þ�ȥ�����ɡ�";
      else
           return "����Ϊ���µ����أ�"+ob->query("name")+"����������" + owner->query("name") +"֮�֣����ȥ����ɱ�ˣ��Ѷ���ȡ������";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "��"+ob->query("name")+"�����ȥ��ϣ�����ܺú����á�";
}

string ask_honglinfen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (me->query_skill("poison",1)<100)
		return "��Ķ������δ�����ò������ֶ�����";
	ob=new(HONGLINFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"��������������";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "�������ˣ�"+ob->query("name")+"���ڲ��������С�";
      if (owner->query("family/family_name") == "������")
           return ob->query("name")+"�����ڱ���" + owner->query("name") +"���У���Ҫ�þ�ȥ�����ɡ�";
      else
           return "����Ϊ���µ����أ�"+ob->query("name")+"����������" + owner->query("name") +"֮�֣����ȥ����ɱ�ˣ��Ѷ���ȡ������";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "��"+ob->query("name")+"�����ȥ��ϣ�����ܺú����á�";
}

string ask_bingpofen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (me->query_skill("poison",1)<100)
		return "��Ķ������δ�����ò������ֶ�����";
	ob=new(BINGPOFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"��������������";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "�������ˣ�"+ob->query("name")+"���ڲ��������С�";
      if (owner->query("family/family_name") == "������")
           return ob->query("name")+"�����ڱ���" + owner->query("name") +"���У���Ҫ�þ�ȥ�����ɡ�";
      else
           return "����Ϊ���µ����أ�"+ob->query("name")+"����������" + owner->query("name") +"֮�֣����ȥ����ɱ�ˣ��Ѷ���ȡ������";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "��"+ob->query("name")+"�����ȥ��ϣ�����ܺú����á�";
}
