// Room: /d/xiangyang/wallw3.c
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
		"northup"   : __DIR__"wallw5",
		"southdown" : __DIR__"wallw1",
	]));
	set("coor/x", -550);
	set("coor/y", -480);
	set("coor/z", 20);
	setup();
}