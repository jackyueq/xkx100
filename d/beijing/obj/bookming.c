// bookming.c

inherit ITEM;

void init()
{
        add_action("do_shake", "doudong");
        add_action("do_shake", "shake");
        add_action("do_shake", "twitter");
}

void create()
{
        set_name("��ʷ����", ({"book ming","book","ming"}));
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������顣\n");
                set("unit", "��");
                set("gold", 1);
                set("material", "paper");
        }
        setup();
}


int do_shake(string arg)
{
	object me,goldleaf1,goldleaf2,newbook;
	me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="book"||arg=="ming"||arg=="ming book") 
	{
                if(query("gold") == 1)
		{
								message("vision","ͻȻ����Ƭ��Ҷ�����е��˳�����\n",environment(me));
                goldleaf1 = new(__DIR__"goldleaf");
                goldleaf1->move(environment(me));
                goldleaf2 = new(__DIR__"goldleaf");
                goldleaf2->move(environment(me));
                set("gold", 0);
                newbook = new(__DIR__"bookming1");
                newbook->move(me);
                destruct(this_object());
    }
		else message("vision","������ô������û��Ҷ�ˡ�\n",environment(me));
	return 1;
	}
}	





