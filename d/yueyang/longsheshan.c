// Room: /d/yueyang/longsheshan.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
��ɽ���ο���������ˮ�����Ѿ�ǰ��Ϊ���ڣ��ſ����ϣ�����ǯ��
ɽ�죬�ұڹ�����Ϊ�����ϡ������м��СɽΪ����ͷ��ɽ��ƽ�棬
��̬���棬��ɽ��˵�������������Ѱ������ɽ���ڿ��쳣�����ǵ���
��ж��˶�ͥ���е���������������һ��Сɽ���ſ�˫�������ͷ��
�����ѵγ�������ɽ���£�����һ�ڹž������������ž���������һ��
������������ѡ��پ��������š�����Ͷ�����������˹��ȣ���Ϊһ
��Сɽ��������������ɽ��
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"liuyijing",
		"southdown" : __DIR__"feilaizhong",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));
	set("coor/x", -1720);
	set("coor/y", 2320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
