// Room: /d/yanziwu/path7.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
һ��С·ͨ�������������С·�ϣ���������������Ϫˮ�졣��
����ʯ�̵ú��������������ǻ��˲��ٹ����ˡ����߾��Ǻ�ϼ¥�ˡ�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"path6",
		"north"  : __DIR__"hongxia1",
	]));
	set("coor/x", 1250);
	set("coor/y", -1260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}