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
                set("gold", 0);
                set("material", "paper");
        }
        setup();
}


int do_shake(string arg)
{
	object me,goldleaf1,goldleaf2;
	me = this_player();

  if( !arg || arg=="" ) return 0;
        if( arg=="book"||arg=="ming"||arg=="ming book") 
	{
	message("vision","������ô������û��Ҷ�ˡ�\n",environment(me));
	return 1;
	}
}	





