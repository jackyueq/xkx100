// /d/beihai/yilan.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������뱱������ͤ��ˮ���������ϲ�����֮�����£��γ�һ����
��ʽ֮����������ʯ�Ҷ�����ʯ����ͤ������������ͨ���������ɣ�
�к����á�д��ʯ�ҡ���᰾��ᡢ����¥��һ�����ͤ��С����ͤ�ȡ�
��¥�������ƺ�������������Ϊ����¥������Ϊ�����󣬷ֱ���Ϊ��
���õ���ڡ��Ǵ�¥����հ��������̲����н�ɽ����һ��֮ʤ��
LONG
	);
	set("exits", ([
		"southup"   : __DIR__"baita",
		"northeast" : __DIR__"dukou2",
		"southwest" : __DIR__"yuegu",
		"southeast" : __DIR__"shiqiao",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
