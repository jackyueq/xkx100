// canglong.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ɽ�������յ��Ǳ��壬����֮����͵����ǲ����롣����
��Լ���ף����һ�ף�����ɽ֮·������ɽ��֮�ϣ����༹�¹⻬ͦ�Σ�
�����������䣬���������������������ƣ����౳�ڣ�������ڿգ���
�������������һʯ��(shibei)��
	��������������ɽ��·�����������������ķ��·�������ǻ�ɽ��
�մ�֮һ�������������¡���
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"westup"   : __DIR__"sheshen",
		"northup"  : __DIR__"yuntai",
		"eastdown" : __DIR__"shangtianti",
	]));
	set("item_desc", ([
		"shibei" :
"ʯ�����ż������֣�������֮Ͷ�鴦������˵���꺫�����ϴ���֮��\n
��Ҳ��������������ΪҪ����ɽ�ϣ�����ɽ��д��Ͷ�������ͼ��˾���\n
�������ǻ����ص��ع�������ɽ�����Ӱ������ŵ������ġ�\n"
]) ) ;
	set("objects", ([
		__DIR__"npc/liang-fa" : 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -880);
	set("coor/y", 210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
 
