// Room: /d/suzhou/nandajie1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�ϴ�����ǳ���ķ����ضΣ�һ�����ϣ�����һ�ɵƺ���̣���Ϊ
���֡�Ц�������������������������һƬ��������Ķ��䣬�㲻����
Գ��������ʹ�ͣ������һ�������ݵĳ���������ɫ��ʱ��ʹ���Ŀ�
��������ʱ�˿�ֻ���������Ȼ�����ľ�ɫ��Ϊһ�塣�����￴ȥ����
���ϳǵĽ־���һƬ���֡��ڽֵĶ�������һ����ݣ�������ȥ��һ��
����԰�֡�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"shizilin",
		"west"      : __DIR__"jubaozhai",
		"north"     : __DIR__"baodaiqiao",
		"south"     : __DIR__"nandajie2",
		"southwest" : __DIR__"shuyuan",
		"northeast" : __DIR__"chaguan",
	]));
	set("coor/x", 850);
	set("coor/y", -1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
