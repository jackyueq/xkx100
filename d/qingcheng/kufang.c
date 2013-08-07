// Room: /d/qingcheng/kufang.c

inherit ROOM;
int do_qiao(string arg);

void create()
{
	set("short", "�ⷿ");
	set("long", @LONG
���������һ�ɵĿⷿ���ղ��Ÿ���;���������䱦���ⷿ���߱�
�Ϲ����һЩ���»�Ƥ������Ƥ��������֪����Ƥë���ϱ߱ڹ����
����һЩ��ʯ��ͭ����Ʒ����������ֵ��Ǯ�ġ���������һ�������䣬
����������ʵ��
LONG );
	set("objects", ([
		__DIR__"obj/xiang" : 1,
	]));
	set("coor/x", -8069);
	set("coor/y", -840);
	set("coor/z", 90);
	setup();
//	replace_program(ROOM);
}
int do_qiao(string arg)
{
	object me=this_player();
	object room;
	if (arg != "men") return 0;
	if(!( room = find_object(__DIR__"zoulang2")) )
		room = load_object(__DIR__"zoulang2");
	if(objectp(room))
	{
		set("exits/west", __DIR__"zoulang2");
		message_vision("$N���˰��쾢�������˿��ˡ�\n",me);
		room->set("exits/east", __FILE__);
		message("vision","�������˰ѿ��Ŵ��ˡ�\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
void init()
{
	add_action("do_qiao","qiao");
}
void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"zoulang2")) )
		room = load_object(__DIR__"zoulang2");
	if(objectp(room))
	{
		room->delete("exits/east");
		message("vision","ֻ��ƹ��һ���������Զ�����������\n",room);
		message("vision","���Ժ�������һ����ͷ����Ӵ���ֽ���ȥ�ˣ�\n", room);
		delete("exits/west");
		message("vision","ֻ��ƹ��һ���������Զ�����������\n",this_object());
		message("vision","���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" , this_object());
	}
}