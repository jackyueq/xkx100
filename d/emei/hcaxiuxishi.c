//Room: hcaxiuxishi.c ��������Ϣ��
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","��������Ϣ��");
      set("long",@LONG
�����Ƕ��һ����ֵ���Ϣ�ҡ���������������������������˺ܶ�ľ����
�м���ҹ�����ֵ�Сʦ̫����˯����
������Ϣ�������������
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north" : __DIR__"hcachanfang", 
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
	set("coor/x", -6210);
	set("coor/y", -1200);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}
