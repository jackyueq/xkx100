// Room: fuheqiaoe.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
�����ǳɶ������⸮���š��ɶ��Թž��Ǵ����׸������Ӻ��ϺӼ�
�Ƕ�������Ϊ��Ȼ�Ļ��Ǻӡ������Ĵ�����Ͽ��������֮�գ���������
���֮�̣��ɶ�ȴ��֮���������سɹ�֮���������������£�����߳�
�ˡ�
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"road2",
		"west" : __DIR__"eastgate",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8000);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

