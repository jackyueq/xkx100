// /d/yixing/clchaifang.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
һ��򵥵Ĳ񷿣���ͨ�İ��ڿ���������ɵ��ӻ���õ�ľ��
���ҵض���ǽ�ǣ��Ա��ǿ��񵶣�chaidao�������㣨tiaozhou������
���и�ˮ�ף�ȴ�Ѿ����ˡ�ʱ��Ҳ�а��ڹ�������
LONG );
	set("exits", ([
		"east" : __DIR__"clzoulang1",
	]));
	set("item_desc",([
		"chaidao"  : "һ�ѷ����Ŀ��񵶡�\n",
		"tiaozhou" : "һ������ɨ�ص����㡣\n",
	]));

	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_steal", 1);

	setup();
}

void init()
{
	add_action("do_get", "get");
}

int do_get(string arg)
{
	object obj;

	if( arg && objectp(obj = present(arg, environment(this_player()))) &&
		obj->is_character() )
	{
		write("�㲻�ܰᶯ��ҵ����塣\n");
		return 1;
	}
	else
		return 0;
} 
