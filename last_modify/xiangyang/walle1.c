// Room: /d/xiangyang/walle1.c
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
		"southup"   : __DIR__"walle3",
		"northdown" : __DIR__"eastgate1",
	]));
	set("coor/x", -450);
	set("coor/y", -510);
	set("coor/z", 10);
	setup();
}