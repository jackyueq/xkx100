// npc: /d/city/npc/bookboss.c
// Last Modified by Winder on Jul. 15 2000

inherit NPC;
inherit F_DEALER;
int ask_me();
int ask_gong();

void create()
{
	set_name("������", ({ "xin youqing","xin" }) );
	set("title","����ϰ�");
	set("gender", "����" );
	set("book_count", 1);
	set("age", 38);
	set("long", "������һ�����Ǹ������ˣ�������δ�ͣ������鷷��Ϊ����Ҳ��Ϊ�Եá�\n");
	set("attitude","friendly");
	set("inquiry",([
	       "��"    : "������ʲô�鶼�У�������ʲô��\n",
	       "here"  : "�����һ������������������ĵ��̡�\n",  
	       "����"  : (: ask_me :),
	       "����"  : (: ask_gong :),
	]));
	set("vendor_goods",({
		"/clone/book/lbook1",
		"/clone/book/lbook2",
		"/clone/book/lbook6",
		"/clone/book/lbook7",
		"/clone/book/lbook8",
		"/clone/book/blade_book0",
		"/clone/book/blade_book1",
		"/clone/book/dodge_book1",
		"/clone/book/dodge_book2",
		"/clone/book/sword_book1",
		"/clone/book/cuff_book",
		"/clone/book/unarmed_book",
	}));
	set("chat_chance", 15);
	set("chat_msg",(
	{
	    "�ϰ���������һ�Ѽ�ë���ӣ����ᵧȥǽ�ϣ�����ϵĳ�����\n",
	    "�ϰ�Ц���ʵ��������飿���ǿ����ֻ�������\n",
	    "�ϰ���������:ʶ���߷��Ĳ�ȡ����ʶ��ǧ������\n",
	    "��������ͷ̾��:���ղ��ܼ��������ĺ��˰���\n",
	}));
     
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}
void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_answer", "answer");
}
int ask_me()
{
	if ((int)this_player()->query_skill("literate",1)<125){ 
		say(
"��������˰��ۣ���" + this_player()->name() + "˵������ô����Ҳ����������ˡ�\n");
            return 1;
        }else{
        say(
        "�����忴��" + this_player()->name() + "һ��,�������ص�˵����\n"
        "��������˭�ĺ���(answer)?\n");
        this_player()->set_temp("pending/answer",1);
        return 1;
      }
}
int ask_gong()
{
        tell_object(this_player(),
        "�����忴����һ��,�������ص�˵����\n"
        "������ǰ���ڴ�����һ���鼮������ҪϤ�ı����Դ������ˡ�\n"
        "ֻ�ǲ�֪��ʱ���˻���ȡ�顣\n"
        );
        return 1;
}
int do_answer(string arg)
{
	object me, ob, book;
	me = this_object();
	ob = this_player();
	if (!ob->query_temp("pending/answer")) return 0;
	ob->delete_temp("pending/answer");
	if (arg == "����˾��Ǩ" && query("book_count"))
	{
   add("book_count", -1);
	 book = new("/u/evil/lbook6");	
	 if ( book->violate_unique())
	 {
	  	destruct(book);
	    write("���������" + ob->name() + "˵������ϧ������һ������\n");
	   	return 1;
	 }
		say(
"�������" + ob->name() + "˵������������������˵ĺ������\n"
"�Ұ����������齻����������\n");
   book->move(ob);
	 message_vision("$N����$nһ���顣\n", me, ob);
	 command("rumor "+ob->query("name")+"�õ�ʷ����ƪ����\n");
   return 1;
  }
   message_vision("$NЦ����ԭ��������"+arg+"����ʧ��ʧ����\n",me);
   return 1;
}
