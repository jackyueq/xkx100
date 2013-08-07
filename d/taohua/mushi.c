// Room: /d/taohua/mushi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
  
    set("short", "Ĺ��");
    set("long",@LONG
����һ��Ĺ�ҡ�Ĺ�Ҷ�����һ���ر��������������⡣�������
һ����ף���Χ��ѷ����������������档һ�Ź����������ǰ������
����һ����¯��һ������ (panzi)��Ĺ�Ҷ������һ�������ٸ��Ļ���
�����ϵ��ٸ���Ц��Ȼ���ͲҰ׵���׼������͵�����γ���һ�����
�Ļ��档��Ȼһ�����紵�����㲻������һ��������
LONG);
	set("item_desc", ([
		"panzi" : @TEXT
    ����ϸ����һ�����ӣ�����һ�����̣�����������ž�Ө��
    ���顣��Щ�����ƺ������ó���(pick zhu)��
TEXT
	]) );
	set("exits", ([
		"up" : __DIR__"mudao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 9010);
	set("coor/y", -3100);
	set("coor/z", -20);
	setup();
}
void init()
{           object me = this_player();
            add_action("do_pick","pick");
            me->set_temp("taohua/Ĺ��", 0); 
}
void reset()
{
        ::reset();
        set("pick_available" , 6);
}
int do_pick(string arg)
{
       object me,obj,killer;

       me = this_player();
       if( !arg || arg!="zhu" )
              return notify_fail("��Ҫ��ʲô? \n");
       if( me->query("family/family_name") == "�һ���" )
              return notify_fail("�����һ�������, ����͵�����Ķ���? \n");
       if ( query("pick_available") )
       {
         message_vision("$N���������ó���һ�����顣\n",this_player() );
         obj = new (__DIR__"obj/mingzhu");
         obj->move(me);
         add("pick_available", -1);
         me->start_busy(3);
         if ( me->query_temp("taohua/Ĺ��") ) return 1;
         killer = new (__DIR__"npc/shoumu") ;
         message_vision("\nͻȻĹ���д���һ�����ţ��������߳�һ����Ĺ��ū��\n"
         "��$N�ȵ������ӸҶ��������˵Ķ�����Ҳ�Ҷ���\n", me);
         killer->move(environment(me));
         killer->kill_ob(me);
         me->set_temp("taohua/Ĺ��", 1);
       }
       return 1;
}