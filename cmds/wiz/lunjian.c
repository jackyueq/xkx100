inherit F_CLEAN_UP;

int main(object me,string arg)
{
  int level=-1;
	if (!wizardp(me))
	  return 0;
	if (arg=="�����Խ�" || arg=="1") 
	  level=0;
	else if (arg=="�����Ƚ�"|| arg=="2") 
	  level=1;
	else if (arg=="��������"|| arg=="3") 
	  level=2;
	else if (arg=="��ʦ�۽�"|| arg=="4") 
	  level=3;
	else 
	  return notify_fail("ֻ��ָ�� �����Խ�(1)�������Ƚ�(2)����������(3)����ʦ�۽�(4) �е�һ����\n");
	return PK_D->start_by_others(level);
}
int help(string arg)
{
write(@help
lunjian <ָ���ı���>

������������ʦ�ֶ�������ɽ�۽���
Ŀǰ����ָ���ı����У������Խ�(1)�������Ƚ�(2)����������(3)����ʦ�۽�(4)��
help
);
return 1;
}