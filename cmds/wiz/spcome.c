// summon command..

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
       
	int i;
	if (!str) return notify_fail("<Syntax>: spcome <object id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) ob = find_object(str);
	if (!ob) return notify_fail("û�����������\n");
	// moving
	if (!clonep(ob)) return notify_fail("�����ƶ�����Դ�����\n");
	if (ob->move(environment(me)))
  {
  	tell_object(me, "���"+(string)ob->query("name")+"ץ�������ǰ��\n");
	  return 1;
	}
	else
	return notify_fail("�޷��ƶ������"+str+"��\n");
}

int help(object me)
{
write(@HELP
ָ���ʽ : comehere <ĳ��>

��ָ������㽫ĳ��(��)ץ������ǰ��
HELP
);
    return 1;
}
