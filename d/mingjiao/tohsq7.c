//TOHSQ7.C

inherit ROOM;

void create()
{
	set("short", "ɽ��·");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹����һ
�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡��ٲ��ڽ���
���ڶ�����ɽ���»��һ����̶��
LONG );
	set("exits", ([
		"north" : __DIR__"hsqmen",
		"south" : __DIR__"tohsq6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52020);
	set("coor/y", 920);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}