inherit ROOM;

void create()
{
	set("short", "�͵��Ժ");
	set("long", @LONG
����͵��Ժ��һ�����֮���Ӷ�����᷿ (room) �д�������
�м�����һ��Ů�ӵ����������ŵİ��(wall)��ס���𶯣��ƺ��ͷ���
�ܵİ�ڶ�Ҫ������������̮һ�㡣����Ҳ���᷿����ʱ����̽ͷ����
�����������ǿ͵���š�
LONG );
        set("no_sleep_room",1);
	set("exits", ([
		"west" : __DIR__"kedian4",
		"east" : __DIR__"kedian3",
		"north" : __DIR__"kedian1",
	]));
	set("item_desc", ([
		"wall" : "\n����һ��ľǽ����ڲ���һ�����񣬱����ҡҡ�λΡ�\n",
	        "room" :
"\n����������ȥ��ֻ�����������ֳֽ䵶��Χ��һ����Ů��ƴ����ɱ��\n"+
"ֻ�Ǹ�����Ů��������Ʒ��ס�ˣ��۲��������ǰ���Ů��ͷ����ð\n"+
"��˿˿��������Ȼ�Ѿ���ȫ������ֻһ���۰���֧����ȥ�������ԵֵС�\n"+
"���ϰ߰ߵ�㶼��Ѫ����\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 3990);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	if(this_player()->query_temp("hastrystab")==6)
	return ::valid_leave(me, dir);
	if (dir == "east" )
	{
	i = (int)me->query_skill("dodge", 1) + random(1000);
	if(i>600) 
        return notify_fail(
	"\n��һ��̤���ͷ���ͻ��һ���������ľ��缤�˳���������һײ��\n"+
	"���ʱ���㲻�ȣ������ڵ���������һ��������\n");
        me -> receive_damage ("qi",50) ;
        me -> receive_wound  ("qi",50) ;
	}
	return ::valid_leave(me, dir);
}

void init()
{
add_action("do_thrust","thrust");
add_action("do_thrust","ci");
add_action("do_thrust","stab");
}

int do_thrust(string arg)
{
	object room, me, man, lma;
	if( !arg || arg!="wall" ) return notify_fail("��Ҫ��ʲô��\n");

	if(!present("blade" , this_player())
	 &&!present("bishou" , this_player())
	 &&!present("sword" , this_player())
	 &&!present("gangjian" , this_player())
	 &&!present("changjian" , this_player())
	 &&!present("duanjian" , this_player()))
	return notify_fail("���õ������²��аɣ�\n");

	if(this_player()->query_temp("hastrystab")<6)
	message_vision( "\n$N�ߵ�ǽ�ߣ�������У���׼ľ��ݺݵ�һ����\n",this_player());
	if(!present("bishou" , this_player()))
	message_vision( "���$N�Ƶ�һ�������в��������Ҳ�̲�����֡�\n",this_player());
        else
	{
	if(this_player()->query_temp("hastrystab")<6)
          {
	if(!( room = find_object(__DIR__"kedian3")) )
		room = load_object(__DIR__"kedian3");
	
	lma= present("lama", room);
	if(objectp(room))
            {
		if(!lma)
		{
		message_vision( "ֻ���۵�һ����ذ�����ᴩ��ľ�壬������ûʲô������\n",this_player());
	        message("vision", "��Ȼһ��ذ�״�ǽ����˽�����\n",room );
		}
		else                   
	        {
	         if(lma->query("ownmake")==1)
		 {
		 message_vision( "ֻ���۵�һ����ذ�����ᴩ��ľ�壬������ûʲô������\n",this_player());
	         message("vision", "��Ȼһ��ذ�״�ǽ����˽�����\n",room );	        	
	         }	
	         else
	         {	
	     	 message_vision( "ֻ���۵�һ����ذ�����ᴩ��ľ�壬������ʱ����һ���ҽС�\n",this_player());
 		 this_player()->add_temp("hastrystab",1);
		 message("vision", "��Ȼһ������ҽ�һ��������ȥ��\n",room );
		 if(objectp(man=present("lama",room))) man->die();		
		 }
		}
	}
	return 1;
	}
	else return notify_fail("���Ѿ�ɱ����������,������ɱ�ˡ�\n");
    }
return 1;
}
