//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ�߽��������ŵ�һ�ɲ���������Ƣ���㲻������Ϊ֮һˬ������
������һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ������
���ƹʺ�ҥ�ԣ������Ǹ������ڡ���Ҳ�ݵ������Ǹ�����֮ʿ������
�������Ҫ���ǡ������ޱߡ���
LONG );
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"dongjie2",
	]));
	set("objects", ([
		__DIR__"npc/chongyi" : 1,
	]));
	set("coor/x", -1460);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}