//Room: lingwenge.c ���ĸ�
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","���ĸ�");
      set("long",@LONG
�����Ǹ����ֵ����ĸ������־���ʦ̫���ڷ𷨵ĵط�����������С��
�������ԣ��ƺ�������ʦ̫�Ľ̻ޡ����ڲ��ü�ª����ǽ���ż������Σ�����
���ż������š�������һ������������һ��ի����
LONG);
      set("objects", ([
           CLASS_D("emei") + "/zhao" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "out"     : __DIR__"fushouan",
          "east"    : __DIR__"fsachanfang",
          "west"    : __DIR__"fsazhaitang",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6100);
	set("coor/y", -1060);
	set("coor/z", 70);
	setup();
      replace_program(ROOM);
}