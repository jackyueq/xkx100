//Room: fuzhenguan.c ��������¥
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","��������¥");
      set("long",@LONG
��������¥�������أ������ʮ�������ʽ����ص����������һ
��֧�ţ��������ġ�һ��ʮ�������������︩�Ⱥɽ���������룬Զ��
�𶥣�һ�����죬Ϊ�۾�ʤ�ء�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"taizipo",
      ]));
      set("objects",([ /* sizeof() == 1 */
          "/clone/medicine/vegetable/mahuang" : random(2),
      ]));
      set("outdoors", "wudang");
	set("coor/x", -2040);
	set("coor/y", -860);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}
