//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "��ͨ��");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɼ嶹Ƥ����ζ�������人��������С�Ե꣬
ϲ���Զ�Ƥ���������Ŀ�����ɢ��������һλ�������˵�����Ů����æ
���š���˵�е��ֺ��ģ��������ڴˣ����������ƹʣ��������ֿɿ�
�Ķ�Ƥ��Ҳ��һ�����¡�
LONG );
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"hzjie2",
	]));
	set("objects", ([
		__DIR__"npc/woman" : 1,
	]));
	set("coor/x", -1510);
	set("coor/y", -2110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}