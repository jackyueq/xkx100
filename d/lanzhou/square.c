//  Room:  /d/lanzhou/square.c

inherit  ROOM;

void  create  ()
{
	set("short",  "������㳡");
	set("long",  @LONG
������һ��ǣ����������ľ������ģ�Ҳ���Ļ����ġ����ݵ��Ļ�
�����ҷ�ɣ����д�ͳ���͡�����������Ӱ�죬Ҳ�лؽ̵�ͶӰ������
���ǡ����ݣ�ϸ�����в��㣬������֮��ȴ�й�֮��
    �����ǳ�����ǰ��һ���㳡���ʷ���ᣬ��Ⱥ�����������㳡����
�յġ������ġ���С�����Ĳ�ͣ�Ĵ���Ǯ�����⡣�����Ǳ��ǵļ��У�
������ͨ������������еĹ�Ժ��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"road2",
		"north" : __DIR__"street2",
		"east"  : __DIR__"market",
		"west"  : __DIR__"cuiying",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2690);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}