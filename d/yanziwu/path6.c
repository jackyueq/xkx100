// Room: /d/yanziwu/path6.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
һ��С·ͨ�������������С·�ϣ���������������Ϫˮ�졣��
����ʯ�̵ú��������������ǻ��˲��ٹ����ˡ��ϱ߾�������ɽׯ�Ļ�
���ˣ���ׯ��԰�Ļ��������Ǳ���������ġ�����ͨ���ϼ¥��������
���ʷ���
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"huapu2",
		"north"  : __DIR__"path7",
		"east"   : __DIR__"shiwu",
		"west"   : __DIR__"path5",
	]));
	set("coor/x", 1250);
	set("coor/y", -1270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}