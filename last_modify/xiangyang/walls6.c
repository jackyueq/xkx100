// Room: /d/xiangyang/walls6.c
// Date: Jan. 8 1999 by Winder
// Modified by Zeratul Jan 15 2001,�����˷������

inherit __DIR__"wall.c";

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���ǵ����ͷ��ʯ�ף���Ϊ��ǽ�ܸߣ����Ժܶ���ʯ����
���пɹ��������µ�б�µ���
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"eastup"   : __DIR__"walls8",
		"westdown" : __DIR__"walls4",
	]));
	set("coor/x", -470);
	set("coor/y", -550);
	set("coor/z", 30);
	setup();
}