// Room: /d/wuxi/wuguanwoshi.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ؽ�ͷ�����ң������ؽ�ͷ���µ����ڶ࣬�ؽ�ͷ��ͷҲ��Ϊ
��£����ﲼ�õ���Ȼ���൱��������ľ�������Ž��л�������˿��
�ʵʹ����ݽ�ȼ��̴�㣬�Ե�ʮ�ְ�����
LONG );
	set("exits", ([
		"west" : __DIR__"wuchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}