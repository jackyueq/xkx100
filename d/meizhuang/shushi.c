// /d/meizhuang/shushi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ͺ���̵����ң�������һ���󰸣����Ϸ���һ����Ͳ����Ͳ
�в��ż��ܴ�С��ͬ��ë�ʣ�ë�ʵ�����Ҳ������ͬ�����Ǻ����������
�����ף������룬����һ֧���Ϻ��Ѽ�����̡���ʣ�����ƽ����һ����
�����ô�С����ֽ��һ�����⣬һ����ī��һ�԰�����ֽ��һ����ɽ��
�ܣ����Գ����˶��鷨�İ��á�ǽ�Ϲ�����������д��һ������������
�ã������� 
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("heimuya")+"/weng" : 1,
	]));
	set("outdoors", "meizhuang");

	set("coor/x", 3490);
	set("coor/y", -1380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
