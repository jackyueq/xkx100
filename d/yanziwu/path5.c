// Room: /d/yanziwu/path5.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
һ��С·ͨ�������������С·�ϣ���������������Ϫˮ�졣��
����ʯ�̵ú��������������ǻ��˲��ٹ����ˡ��ϱ߾�������ɽׯ�Ļ�
���ˣ���ׯ��԰�Ļ��������Ǳ���������ġ������������ɽׯ������
��԰�ˡ�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"huapu1",
		"east"   : __DIR__"path6",
		"west"   : __DIR__"garden",
	]));
	set("coor/x", 1240);
	set("coor/y", -1270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}