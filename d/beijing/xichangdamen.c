inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��������������ţ����Կ������������̫�ࡣ�����Ʒ��Ĺٱ���
�ڲ�������ʱ�ش����ź���������㲻�������Ļ�����û��ǸϿ��뿪
�ɡ�
LONG );
	set("exits", ([
		"south" : __DIR__"bingyin2",
		"north" : __DIR__"di_an4",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -210);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("�ٱ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}
