// gudi.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "�ȵ�");
	set("long", @LONG
�����ö��ߺ�����������Խ��Խ��ɽ��Ҳ�𽥱����б��������
��������ô���ͱ����ˣ����ڵ���ȵ��ˡ�ֻ�����������һ�����ٲ�
���������գ��������£�������һ���峺�쳣�Ĵ��֮�С��ٲ�ע�봦
��ˮ������ֻ����ٲ�ʮ���ɣ���ˮ��һƽ�羵��
LONG );
	set("exits", ([
		"up" : __DIR__"yanfeng",
		"west" : __DIR__"hubian",
	]));
	set("outdoors", "wuliang" );
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21060);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}