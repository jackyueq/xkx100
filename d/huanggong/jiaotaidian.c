// Room: /d/huanggong/jiaotaidian.c

inherit ROOM;

void create()
{
	set("short", "��̩��");
	set("long", @LONG
���ͤ���η���ǻʺ��������ף��С���á���̩����Դ�� <��
��> ������ؽ���̩�������з�����������������Ȩ���Ķ�ʮ��ű�����
������һ��ͭ����©��������һ�ܴ������ӡ�ÿ�괺�����ʺ��ڴ˾���
ι������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		 "north" : __DIR__"kunninggong",
		 "south" : __DIR__"qianqinggong",
	]));
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/yuma" : 1,
	]));

	set("coor/x", -200);
	set("coor/y", 5300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}