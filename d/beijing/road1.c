inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ��
��������������߷ɳ۶���������һ·��������·���������������
�����֡����߾��Ǿ��Ƕ��š���������һ��С·��
LONG );
	set("exits", ([
		"west"      : __DIR__"dongmen",
		"southeast" : __DIR__"road2",
		"northeast" : __DIR__"zhuang1",
	]));
	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));
 	set("outdoors", "huabei");
	set("coor/x", -160);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

