// Room: /d/yanziwu/chalin3.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "�軨��");
	set("long", @LONG
���ڻ����е���ײײ�����Ƕ��У���֪�������ǳ��ڣ���ʱ������
��ֻ�ǲ軨�����˼���·�����ۼ�С·��һ������һ����Ҳ��֪��һ��
������·��Ҫ�ص�С��ͣ����ȴ�е�����ˣ����������룺�����ߵ�ˮ
����˵����
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"chalin1",
		"east"  : __DIR__"chalin4",
		"south" : __DIR__"chalin3",
		"north" : __DIR__"chalin5",
	]));
	set("coor/x", 1190);
	set("coor/y", -1290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}