// Room: /d/huangshan/feicui.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���ɹ�Ϫ�ߣ������岼��������̶��ƽʱ̶ˮ�峺ƽ����ÿ��΢��
����������΢�����������ۣ����Խ���̶������ˮɫ��Ϊ�࣬�࣬�ڣ�
�ף��ϣ�����һ̶��ˮ�����������Ա���Ϊ���ء�����ʯ����ʯ����
������̣�Ӧ�о��У����з�ζ����˵�������µ�����������������̶
�����Ҳ��֪��١�
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"songgu",
	]));
	set("objects", ([
		__DIR__"obj/pond1" : 1,
		__DIR__"obj/pond2" : 1,
		__DIR__"obj/pond3" : 1,
		__DIR__"obj/pond4" : 1,
		__DIR__"obj/pond5" : 1,
		__DIR__"obj/pond6" : 1,
	]) );

	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
