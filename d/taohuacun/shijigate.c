// /d/taohuacun/shijigate.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "�һ�����" );
	set( "long", @LONG
�����¿���һ���м�������˷����̷����ۼ����˴����ò����֡�
�м�������������������ʱ������Ķ��У��ǵ����������ģ��̲�ס
���ȥ���ơ�
LONG
	);
	set( "exits", ([
		"north" : __DIR__"shiji1",	
		"south" : __DIR__"taohua6",	
	]));
        set("outdoors", "taohuacun");		
	set("coor/x", -100);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}