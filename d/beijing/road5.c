inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ��
��������������߷ɳ۶���������һ·��������·���������������
�����֡����߾����������ˡ�
LONG );
	set("exits", ([
		"west"      : "/d/xueshan/bieyuan",
		"north"     : __DIR__"yongding",
		"southeast" : __DIR__"road6",
	]));
	set("objects",([
		"/d/taishan/npc/seng-ren" : 1,
	]));
 	set("outdoors", "huabei");
	set("coor/x", -200);
	set("coor/y", 4000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

