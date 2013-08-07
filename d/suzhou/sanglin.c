// Room: /d/suzhou/sanglin.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "ɣ��");
	set("long", @LONG
������һƬɣ�֡�����˿��������£�����������¾�Ʒ��������
�۵�����ɣ���������Ŵ�����˿����ں�������ʺ��˿�У��㵹�е�
��ժ�¼�Ƭ��ǰ��ƽ��������ɣҶ���úÿ�����
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("ye_count", 5);
	set("exits", ([
		"southwest" : __DIR__"road1",
	]));
	set("coor/x", 1000);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
	object ye, me = this_player();

	if( !arg || arg=="" )
	{
		message_vision("����ժʲô��\n", me);
		return 1;
	}
	if( arg=="ye"||arg=="sang ye" )
	{
		if(query("ye_count") > 0)
		{
			message_vision("$N��ɣ����ժ��һƬ�����͵�ɣҶ��\n",me);
			ye = new("/clone/medicine/vegetable/sangye");
			ye->move(me);
			add("ye_count",-1);
			return 1;
		}
		else
		{
			message_vision("ɣҶ��̫���ˣ�$N��һ����ժ�ɡ�\n",me);
			return 1;	     
		}
	}
	return 0;
}
